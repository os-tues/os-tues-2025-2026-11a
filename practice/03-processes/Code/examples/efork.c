#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
    } else if (pid > 0) {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        perror("fork failed");
    }
    return 0;
}
