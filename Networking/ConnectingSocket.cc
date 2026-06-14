#include "ConnectingSocket.hpp"

ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface):
    Socket(domain, service, protocol, port, interface)
{
    // int connection = connectToNetwork(getSock(), getAddress());
    setConnection(connectToNetwork(getSock(), getAddress()));

    testConnection(Socket::TypeOfSocket::Connect, getConnection());
}

// virtual function from Socket.hpp class
int ConnectingSocket::connectToNetwork(int sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}