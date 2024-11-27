#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Before exec()\n");
        execl("/bin/ls", "ls", "-l", NULL);
        perror("exec failed"); // Only runs if exec fails
    } else if (pid > 0) {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    } else {
        perror("fork failed");
    }
    return 0;  
}