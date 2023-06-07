#ifndef SOCKET_CONNECTION_H
#define SOCKET_CONNECTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <ws2tcpip.h>

#define PORT 9909

int createSocket() {
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return socketFd;
}

void connectToServer(int socketFd, char* ipAddr) {
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, ipAddr, &serverAddr.sin_addr) <= 0) {
        perror("Invalid IP address");
        exit(EXIT_FAILURE);
    }
    if (connect(socketFd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
}

#endif /* SOCKET_CONNECTION_H */
