// client.c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server;
    char message[1024], server_reply[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    send(sock, message, strlen(message), 0);

    int read_size = recv(sock, server_reply, sizeof(server_reply), 0);
    server_reply[read_size] = '\0';
    printf("Server replied: %s\n", server_reply);

    close(sock);
    return 0;
}
