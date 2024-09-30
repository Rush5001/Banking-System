
#include "../include/Server.hpp"
#include <iostream>
#include <thread>
#include <winsock2.h>  // Windows-specific socket header
#include <ws2tcpip.h>  // For additional socket functions
#pragma comment(lib, "Ws2_32.lib")  // Link against Winsock library

Server::Server(int port) : serverPort(port) {}

void Server::start() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  // Initialize Winsock
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        std::cerr << "Listen failed. Error: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    std::cout << "Server listening on port " << serverPort << std::endl;

    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Failed to accept connection. Error: " << WSAGetLastError() << std::endl;
            continue;
        }

        clients.push_back(clientSocket);
        std::thread(&Server::handleClient, this, clientSocket).detach();
    }

    closesocket(serverSocket);  // Close the listening socket
    WSACleanup();  // Cleanup Winsock
}

void Server::handleClient(SOCKET clientSocket) {  // Use SOCKET type for the parameter
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            std::cerr << "Client disconnected." << std::endl;
            closesocket(clientSocket);
            break;
        }
        std::cout << "Received: " << buffer << std::endl;
    }
}

void Server::stop() {
    for (SOCKET clientSocket : clients) {
        closesocket(clientSocket);  // Use closesocket for Windows
    }
}
