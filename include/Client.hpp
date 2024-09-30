
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
private:
    std::string serverAddress;
    int serverPort;

public:
    Client(const std::string& address, int port);

    void connectToServer();
    void sendMessage(const std::string& message);
};

#endif
