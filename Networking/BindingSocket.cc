#include "BindingSocket.hpp"

BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) :
    Socket(domain, service, protocol, port, interface) 
{
    // int connection = connectToNetwork(getSock(), getAddress());
    setConnection(connectToNetwork(getSock(), getAddress()));

    testConnection(Socket::TypeOfSocket::Bind, getConnection());
}

// virtual function from Socket.hpp class
int BindingSocket::connectToNetwork(int sock, struct sockaddr_in address) {
    return  bind(sock, (struct sockaddr *)&address, sizeof(address));
}
