#include "Sockety.h"
#include <stdexcept>
#include <iostream>

Sockety::Sockety()
{
	endMessage = ":stop";
}

Sockety::~Sockety()
{
    closesocket(connectSocket);
    WSACleanup();
}

void Sockety::vytvorPripojenieKlient(std::string adresa, short port)
{
    WSADATA wsaData;
    sockaddr_in serverAddr;
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) 
    {
        throw std::runtime_error("WSAStartup failed with error : " + std::to_string(iResult) + "\n");
    }

    // Create a TCP socket
    connectSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (connectSocket == INVALID_SOCKET) {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(iResult) + "\n");
    }

    // Resolve the server's address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to the server's IP address
    serverAddr.sin_port = htons(port);

    // Connect to the server
    if (connect(connectSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        closesocket(connectSocket);
        WSACleanup();
        throw std::runtime_error("Unable to connect to server.\n");
    }
    
}

void Sockety::vytvorSocketServer(short port)
{
    WSADATA wsaData;
    SOCKET serverSocket;
    sockaddr_in serverAddr;
    int recvResult;
    char buffer[1024];
    int bufferSize = sizeof(buffer);
    char responseBuffer[1024];
    int responseBufferSize = sizeof(responseBuffer);

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Create a TCP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket: " << WSAGetLastError() << std::endl;
        return;
    }

    // Bind the socket to address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }

    // Wait for a client to connect
    sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error accepting connection: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return;
    }
}

void Sockety::posliData(std::string data)
{
    char messageBuffer[1024];
    int messageBufferSize = sizeof(messageBuffer);
    int sendResult;
    // Send the message to the server
    strcpy(messageBuffer, data.c_str());
    sendResult = send(connectSocket, messageBuffer, messageBufferSize, 0);
    if (sendResult == -1) {
        closesocket(connectSocket);
        WSACleanup();
        throw std::runtime_error("Error sending message");
    }
}

std::string Sockety::prijmiData()
{
    // Receive the response from the server
    char responseBuffer[1024];
    int responseBufferSize = sizeof(responseBuffer);
    //std::string response;
    int recvResult;

    if ((recvResult = recv(connectSocket, responseBuffer, responseBufferSize, 0)) > 0) {
        std::string response(responseBuffer);
        return response;
        std::cout << "Server response: " << responseBuffer << std::endl;
    }
    else if (recvResult == 0) {
        std::cout << "Server disconnected" << std::endl;
    }
    else {
        std::cerr << "Error receiving response: " << WSAGetLastError() << std::endl;
    }
    return "";
}
