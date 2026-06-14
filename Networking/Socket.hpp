#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>



class Socket{

private:
    struct sockaddr_in address;
    int sock {};
    int connection {};

public:
    enum class TypeOfSocket {
        Bind,
        Connect,
        Listen,
        Socket
    };

    Socket(int domain, int service, int protocol, int port, u_long interface);
    virtual int connectToNetwork(int sock, struct sockaddr_in address) = 0;
    void testConnection(TypeOfSocket typeOfSocket, int itemToTest);

    struct sockaddr_in getAddress();
    int getSock();
    int getConnection();
    void setConnection(int con);

};