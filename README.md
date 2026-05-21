# Chat Haus
* This terminal-based chat application utilizes language features provided by the concurrency support library sub-component (of the C++ standard library) that facilitate the implementation of concurrent programs (running on a single CPU core) by way of multithreaded programming techniques. The Client-Server Model employed by this application was implemented using C-based POSIX functions from a couple of included header files which enable socket programming. 

## Development Environment:
* Lenovo T14 Gen 6 (x86_64)
* Ubuntu 24.04.3
* GNOME Terminal 3.52.0
* Vi IMproved 9.1


## Dependencies:
* GCC 16.1 or newer (in order to use the most up to date version of G++)
* Git 2.43.0 or newer

## Target Environment:
* Ubuntu 24.04.3 (x86_64)

# How to Run

1. Clone the repo
```
git clone https://github.com/lucasthormann/cxx-chat.git
```

2. Run the following command in order to preprocess, compile, assemble, and link the files using G++ (a C++ compiler included in the GNU Compiler Collection)
```
g++ server.cpp -lpthread -o server && g++ client.cpp -lpthread -o client
```

3. Use the following instruction to run the server executable
```
./server
```

4. Next, use the following command to run the client executable
```
./client
```
5. In order to have multiple client instances connected to the server simultaneously repeat step 4
