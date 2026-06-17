#include "Server.hpp"

Server::Server(int domain, int service, int protocol, int port, u_long interface, int bklg){
    socket = new ListeningSocket(domain, service, protocol, port, interface, bklg);
}

ListeningSocket *Server::getSocket(){
    return socket;
}