#include <iostream>

template <typename T>
class Server {
 public:
  Server() {
    std::cout << "Server<" << typeid(T).name() << "> created\n";
  }
  virtual void run() {
    std::cout << "Server<" << typeid(T).name() << "> running\n";
  }
};

using HttpServer = Server<int>;

template<> 
HttpServer::Server() {
  std::cout << "HttpServer created\n";
}

template<> 
void HttpServer::run() {
  std::cout << "HttpServer running\n";
}

int main() {
  HttpServer server;
  server.run();
}