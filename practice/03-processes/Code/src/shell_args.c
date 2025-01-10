#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    ssize_t bytes_read;

    while (1) {
        write(STDOUT_FILENO, "shell> ", 7);

        bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH - 1);
        if (bytes_read <= 0) {
            perror("Read error");
            continue;
        }

        command[bytes_read] = '\0';
        if (command[bytes_read - 1] == '\n') {
            command[bytes_read - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) break;

        char *token = strtok(command, " ");
        int arg_count = 0;

        while (token != NULL && arg_count < MAX_ARGS - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);
            perror("Command execution failed");
            _exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
