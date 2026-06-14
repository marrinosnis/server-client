#include "TestServer.hpp"


TestServer::TestServer(): Server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10) {
    launch();
}


void TestServer::accepter() {
    struct sockaddr_in address = getSocket()->getAddress();
    int addrlen = sizeof(address);
    newSocket = accept(getSocket()->getSock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    read(newSocket, buffer, 30000);
}

void TestServer::handler() {
    std::cout << buffer << '\n';
}

void TestServer::responder() {
    char *hello = "Hello from server";
    write(newSocket, hello, strlen(hello));
    close(newSocket);
}

void TestServer::launch() {
    while(true) {
        std::cout << "======= WAITING =======\n";
        accepter();
        handler();
        responder();
        std::cout << "======= DONE  =========\n";
    }
}