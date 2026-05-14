This terminal based chat application utalizes language features provided by the Concurrency Support Library that facilitate the implementation of concurrent programs (running on a single CPU core) by way of multithreaded programming techniques. The Client-Server Model employed by this application was implemented using C-based POSIX functions from a couple of included header files which enable socket programming. 

## Dependencies:
* GCC 16.1 or newer in order to use the most up to date version of G++
* Ubuntu 24.04 LTS or later

# How To Compile and Run

1. Clone the repo
```
git clone https://github.com/lucasthormann/cxx-chat.git
```

3. Run the following commands within your terminal in order to compile the files using g++ (a C++ compiler included in the GNU Compiler Collection)
```
g++ server.cpp -lpthread -o server
g++ client.cpp -lpthread -o client
```

3. To run the server executable via a Bash command use the following instruction within the GNOME terminal (if using Noble Numbat)
```
./server
```

4. Next run the client executable using the following command
```
./client
```
5. In order to have multiple client instances connected to the server simultaneously repeat step 4
