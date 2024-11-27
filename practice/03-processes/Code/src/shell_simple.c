#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char command[256];
    while (1) {
        printf("shell> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        
        if (strcmp(command, "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {
            execlp(command, command, NULL);
            perror("Execution failed");
            return 1;
        } else {
            wait(NULL);
        }
    }
    return 0;
}