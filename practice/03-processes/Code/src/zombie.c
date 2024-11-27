#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0);
    } else {
        printf("Parent process (PID: %d) is sleeping for 30 seconds...\n", getpid());
        printf("Child process (PID: %d) should now be a zombie. Use `ps` to confirm.\n", pid);
        sleep(30);
        printf("Parent process is now reaping the child process...\n");
        wait(NULL);
        printf("Child process reaped. No more zombie.\n");
    }

    return 0;
}
