//
//  ex12_04_05.cpp
//
//  Created by Tang Chengming on 05/19/2021
//
//  @Brief  exercise 12.4 编写自己版本的用 shared_ptr 管理 connection 的例子.
//          exercise 12.5 使用 lambda 代替 end_connection.

#include <iostream>
#include <memory>
#include <string>

struct Destination;
struct Connection;
Connection &connect(Destination const &);
void        disconnect(Connection const &);
void        endConnection(Connection *pConn) {
    disconnect(*pConn);
}

struct Destination {
    std::string _ip;
    int         _port;
    Destination(std::string ip, int port) : _ip(ip), _port(port) {}
};
struct Connection {
    std::string _ip;
    int         _port;
    Connection(Destination const &dest) : _ip(dest._ip), _port(dest._port) {}
};

Connection &connect(Destination const &dest) {
    std::cout << "connect(" << dest._ip << ", " << dest._port << ")" << std::endl;
    return *new Connection(dest);
}

void disconnect(Connection const &conn) {
    std::cout << "disconnect(" << conn._ip << ", " << conn._port << ")" << std::endl;
    delete &conn;
}

int main() {
    Destination dest("127.0.0.1", 3333);
    // exercise 12.14
    std::shared_ptr<Connection> pConn1(&connect(dest), endConnection);
    // exercise 12.15
    auto                        end = [](Connection *pConn) { disconnect(*pConn); };
    std::shared_ptr<Connection> pConn2(&connect(dest), end);
    return 0;
}
