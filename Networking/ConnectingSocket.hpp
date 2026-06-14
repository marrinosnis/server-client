#pragma once

#include "Socket.hpp"

class ConnectingSocket: public Socket {

public:
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
    int connectToNetwork(int sock, struct sockaddr_in address);
};