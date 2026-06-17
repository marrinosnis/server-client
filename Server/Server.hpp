#pragma once

// #include <iostream>
#include <unistd.h>
#include "ListeningSocket.hpp"


class Server {

private:

    ListeningSocket *socket;
    virtual void accepter() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;


public:
    
    Server(int domain, int service, int protocol, int port, u_long interface, int bklg);
    virtual void launch() = 0;

    ListeningSocket *getSocket();
};