#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
    }

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid > 0) {
        // Parent
        // grep

        // close write end of pipe, because it won't be used
        close(pipefd[1]);

        waitpid(pid, NULL, 0);
        close(STDIN_FILENO);
        dup(pipefd[0]);
        close(pipefd[0]);
        if (execlp("grep", "grep", ".c", NULL) == -1) {
            perror("exec grep");
        }
    }

    if (pid == 0) {
        // Child
        // ls -la

        // close read end of pipe, because it won't be used
        close(pipefd[0]);

        close(STDOUT_FILENO);
        dup(pipefd[1]);
        close(pipefd[1]);

        if (execlp("ls", "ls", "-la", NULL) == -1) {
            perror("exec ls");
        }
    }
    return 0;
}
