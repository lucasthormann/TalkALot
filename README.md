This terminal-based chat application utilizes language features provided by the concurrency support library sub-component (of the C++ standard library) that facilitate the implementation of concurrent programs (running on a single CPU core) by way of multithreaded programming techniques. The Client-Server Model employed by this application was implemented using C-based POSIX functions from a couple of included header files which enable socket programming. 

## Development Environment:
* Lenovo T14 Gen 6 (x86_64)
* Ubuntu 24.04.3
* GNOME Terminal 3.52.0
* Vi IMproved 9.1


## Dependencies:
* GCC 16.1 or newer in order to use the most up to date version of G++
* Git 2.43.0 or newer

# How To Run

1. Clone the repo
```
git clone https://github.com/lucasthormann/cxx-chat.git
```

3. Run the following commands in order to preprocess, compile, assemble, and link the files using G++ (a C++ compiler included in the GNU Compiler Collection)
```
g++ server.cpp -lpthread -o server
g++ client.cpp -lpthread -o client
```

3. To run the server executable use the following instruction
```
./server
```

4. Next, run the client executable using the following command
```
./client
```
5. In order to have multiple client instances connected to the server simultaneously repeat step 4
