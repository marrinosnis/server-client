#include "Socket.hpp"

Socket::Socket(int domain, int service, int protocol, int port, u_long interface){
    
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    //establish socket 
    sock = socket(domain, service, protocol);
    testConnection(Socket::TypeOfSocket::Socket, sock);

}


void Socket::testConnection(Socket::TypeOfSocket typeOfSocket, int itemToTest){
    if (itemToTest < 0){
        std::cerr << "Failed to connect...\n";
        
        switch(typeOfSocket) {
            case TypeOfSocket::Bind:
                perror("binding ERROR");
                break;
            case TypeOfSocket::Listen:
                perror("listening ERROR");
                break;
            case TypeOfSocket::Connect:
                perror("connecting ERROR");
                break;
            default:
                std::cerr << "No Valid Type of Socket\n";
        }
                
        
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in Socket::getAddress(){
    return address;
};

int Socket::getSock(){
    return sock;
}

int Socket::getConnection(){
    return connection;
}

void Socket::setConnection(int con) {
    connection = con;
}
