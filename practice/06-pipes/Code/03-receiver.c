#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PIPE_NAME "chat_pipe"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
    }

    fd = open(PIPE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Waiting for messages...\n");
    while (1) {

        ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesRead == -1) {
            perror("read");
            break;
        }
        if (bytesRead == 0) {
            printf("Sender has disconnected. Exiting...\n");
            break;
        }

        buffer[bytesRead] = '\0';

        printf("Received: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Sender has exited the chat.\n");
            break;
        }
    }

    close(fd);
    unlink(PIPE_NAME);
    return 0;
}