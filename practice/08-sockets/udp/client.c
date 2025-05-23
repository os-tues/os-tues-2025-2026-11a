#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8181

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_aton("127.0.0.1", &server_addr.sin_addr);

    const char *msg = "Hello, server!";
    sendto(sockfd, msg, strlen(msg), 0,
           (const struct sockaddr *) &server_addr, sizeof(server_addr));
    printf("Client sent a message\n");

    socklen_t len = sizeof(server_addr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                     (struct sockaddr *) &server_addr, &len);
    buffer[n] = '\0';
    printf("Client received: %s\n", buffer);

    close(sockfd);
    return 0;
}
