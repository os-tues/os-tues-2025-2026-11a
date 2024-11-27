#define _POSIX_SOURCE
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        while (1) printf("Running...\n");
    } else {
        sleep(2);
        kill(pid, SIGKILL);
        printf("SIGKILL sent to %d\n", pid);
    }
    return 0;
}
