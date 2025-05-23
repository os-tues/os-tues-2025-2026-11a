// server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8181

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket create");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 3) == -1) {
        perror("listen");
        return 1;
    }

    printf("Waiting for a client to connect...\n");

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int clientfd = accept(sockfd, (struct sockaddr *)&client_address, &client_address_len);
    if (clientfd == -1) {
        perror("accept");
        return 1;
    }

    printf("Client connected. Sending file...\n");

    int filefd = open("example.txt", O_RDONLY);
    if (filefd == -1) {
        perror("open file");
        return 1;
    }

    char buffer[1024];
    ssize_t read_bytes;
    while ((read_bytes = read(filefd, buffer, sizeof(buffer))) > 0) {
        ssize_t sent_bytes = write(clientfd, buffer, read_bytes);
        if (sent_bytes != read_bytes) {
            perror("write");
            return 1;
        }
    }

    close(filefd);
    close(clientfd);
    close(sockfd);
    printf("File sent successfully.\n");
    return 0;
}
