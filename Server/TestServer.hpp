#include <cstring>

#include "Server.hpp"

class TestServer: public Server {
private:

    char buffer[30000] = {0};
    int newSocket {};

    void accepter();
    void handler();
    void responder();

public:
    TestServer();
    void launch();

};