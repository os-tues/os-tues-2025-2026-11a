#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8181

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(client_addr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, 
                     (struct sockaddr *) &client_addr, &len);
    buffer[n] = '\0';
    printf("Server Received: %s\n", buffer);

    const char *reply = "Message received";
    sendto(sockfd, reply, strlen(reply), 0,
           (const struct sockaddr *) &client_addr, len);
    printf("Server sent response\n");

    close(sockfd);
    return 0;
}
