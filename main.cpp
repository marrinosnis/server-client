
// #include <print>
#include <format>

#include <BindingSocket.hpp>
#include <ConnectingSocket.hpp>
#include <ListeningSocket.hpp>
#include <Socket.hpp>

using namespace std;


int main(int argc, char* argv[]) {

	// println("Starting...");
	cout << format("Starting...\n\n");
	BindingSocket bs = BindingSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
	// println("Listening Socket...");
	cout << format("Listening socket...\n\n");
	ListeningSocket ls = ListeningSocket(AF_INET, SOCK_STREAM, 0, 8081, INADDR_ANY, 10);
	// println("Success");
	cout << format("Success...\n\n");
	return 0;

}
