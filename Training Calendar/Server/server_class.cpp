#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

class Socket {
public:
    Socket() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "WSAStartup failed.\n";
            exit(EXIT_FAILURE);
            fnctl(O_NONBLOCK)
        }
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
            std::cerr << "Could not create socket.\n";
            exit(EXIT_FAILURE);
        }
    }

    void bind(int port) {
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(port);
        if (::bind(sock, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
            std::cerr << "Bind failed.\n";
            exit(EXIT_FAILURE);
        }
    }

    void listen() {
        if (::listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            std::cerr << "Listen failed.\n";
            exit(EXIT_FAILURE);
        }
    }

    SOCKET accept() {
        SOCKET new_socket;
        sockaddr_in client;
        int c = sizeof(struct sockaddr_in);
        new_socket = ::accept(sock, (struct sockaddr *)&client, &c);
        if (new_socket == INVALID_SOCKET) {
            std::cerr << "Accept failed.\n";
            exit(EXIT_FAILURE);
        }
        return new_socket;
    }

private:
    SOCKET sock;
};

int main() {
    Socket s;
    s.bind(8080);
    s.listen();
    while (true) {
        SOCKET new_socket = s.accept();
        char buffer[1024] = {0};
        const char *hello = "Hello from server";
        int valread = recv(new_socket , buffer, 1024, 0);
        printf("%s\n",buffer );
        send(new_socket , hello , strlen(hello) , 0 );
        printf("Hello message sent\n");
        closesocket(new_socket);
    }
}