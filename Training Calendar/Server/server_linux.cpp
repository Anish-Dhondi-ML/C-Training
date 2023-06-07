#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

class Socket {
public:
    // Creating socket file descriptor in cunstructor
    Socket() {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            std::cerr << "Could not create socket.\n";
            exit(EXIT_FAILURE);
           
        }
    }

    void bind(int port) {
        
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(port);
        if (::bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            std::cerr << "Bind failed.\n";
            exit(EXIT_FAILURE);
        }
    }

    void listen() {
        if (::listen(sock, SOMAXCONN) < 0) {
            std::cerr << "Listen failed.\n";
            exit(EXIT_FAILURE);
        }
    }

    int accept() {
        int new_socket;
        sockaddr_in client;
        int c = sizeof(struct sockaddr_in);
        new_socket = ::accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (new_socket < 0) 
        {
            std::cerr << "Accept failed.\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            fcntl(new_socket, F_SETFL, O_NONBLOCK);
            return new_socket;
        }

        
    }

    void setsockopt(int level, int optname, ) {
        if (::setsockopt(sock, level, optname, &opt, sizeof(opt)) < 0) 
        {
            std::cerr << "setsockopt failed.\n";
            exit(EXIT_FAILURE);
        }
    }

private:
    int sock;
    int opt= 1;
    struct sockaddr_in server;
};

int main() {
    Socket s;
    s.setsockopt(SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT);
    s.bind(8080);
    s.listen();
    while (true) {
        int new_socket = s.accept();
        char buffer[1024] = {0};
        const char *hello = "Hello from server";
        int valread = read(new_socket , buffer, 1024);
        std::clog << buffer << std::endl;
        send(new_socket , hello , strlen(hello) , 0 );
        std::clog << "Hello message sent" << std::endl;
        close(new_socket);
    }
}