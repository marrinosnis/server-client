#include "ListeningSocket.hpp"

ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg) : 
    BindingSocket(domain, service, protocol, port, interface)
{
    backlog = bklg;
    startListening();
    testConnection(Socket::TypeOfSocket::Listen, listening);
}

void ListeningSocket::startListening() {
    listening = listen(getSock(), backlog);
}
