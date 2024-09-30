
#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <winsock2.h>  // Include Winsock2 header for SOCKET type on Windows

class Server {
private:
    int serverPort;
    std::vector<SOCKET> clients;  // Use SOCKET type for client socket descriptors

public:
    Server(int port);

    void start();
    void stop();
    void handleClient(SOCKET clientSocket);  // Change parameter type to SOCKET
};

#endif
