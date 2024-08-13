#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#define MAX_LEN 200
#define NUM_COLORS 6

using namespace std;

struct terminal{
  int id;
  string name;
  int socket;
  thread th;
};

vector<terminal> clients;
string def_col = "\033[0m";
string colors[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};
int seed = 0;
mutex cout_mtx, clients_mtx;

string color(int code);
void set_name(int id, char name[]);
void shared_print(string str, bool endLine);
int broadcast_message(string message, int sender_id);
int broadcast_message(int num, int sender_id);
void end_connection(int id);
void handle_client(int client_socket, int id);

int main(){
  int server_socket;
  if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    perror("socket: ");
    exit(-1);
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(10000);
  server.sin_addr.s_addr = INADDR_ANY;
  bzero(&server.sin_zero, 0);

  if((bind(server_socket,(struct sockaddr *)&server,sizeof(struct sockaddr_in)))==-1)
  {
   perror("bind error: ");
    exit(-1);
  }

  if((listen(server_socket,8))==-1)
  {
    perror("listen error: ");
    exit(-1);
  }

  struct sockaddr_in client;
  int client_socket;
  unsigned int len = sizeof(sockaddr_in);

  cout << color[NUM_COLORS-1] << "\n\t ====== Welcome to the TalkALot Chat Haus ======   " << endl << def_col;

  while(1){
    if((client_socket = accept(server_socket, (struct sockaddr *) &client, &len)) == -1){
      perror("accept error: ");
      exit(-1);
    }
    seed++;
    thread t(handle_client, client_socket, seed);
    lock_guard<mutex> guard(clients_mtx);
    clients.push_back({seed, string("Anonymous"), client_socket, (move(t))});
  }
  
  for(int i = 0; i < clients.size(); i++){
    if(clients[i].th.joinable()){
      clients[i].th.join();
    }
  }
  
  close(server_socket);
  return 0;
}
