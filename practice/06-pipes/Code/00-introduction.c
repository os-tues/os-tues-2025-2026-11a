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

    // int flags = fcntl(pipefd[0], F_GETFL, 0);
    // fcntl(pipefd[0], F_SETFL, flags | O_NONBLOCK);
    // flags = fcntl(pipefd[1], F_GETFL, 0);
    // fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);
    printf("%d %d\n", pipefd[0], pipefd[1]);
    //                   ^ read     ^ write

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid > 0) {
        // Parent
        char *buf = "hello";
        sleep(1); // delay write
        if (write(pipefd[1], buf, 6) == -1) {
            perror("write");
        }
        close(pipefd[1]);
        wait(NULL);
    }


    if (pid == 0) {
        // Child
        char buf[6] = "empty\0";
        // Read will return error if O_NONBLOCK is set
        // otherwise it will block the process until
        if (read(pipefd[0], &buf, 6) ==-1) {
            perror("read");
        }
        printf("%s\n", buf);
    }
    return 0;
}
