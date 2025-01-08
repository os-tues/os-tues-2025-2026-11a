#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    int pipefd1[2], pipefd2[2];
    if (pipe(pipefd1) == -1)
    {
        perror("pipe 1");
    }

    if (pipe(pipefd2) == -1)
    {
        perror("pipe 2");
    }

    int pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    if (pid == 0)
    {
        // Child
        // ls -la

        close(pipefd1[0]);
        close(STDOUT_FILENO);
        dup(pipefd1[1]);
        close(pipefd1[1]);
        if (execlp("ls", "ls", "-la", NULL) == -1)
        {
            perror("exec ls");
            return 1;
        }
    }

    // waitpid(pid, NULL, 0);
    close(pipefd1[1]);

    pid = fork();
    if (pid == -1)
    {
        perror("fork pid_second");
    }
    if (pid == 0)
    {
        // Child - run grep .c
        close(pipefd2[0]);

        close(STDIN_FILENO);
        dup(pipefd1[0]);

        close(pipefd1[0]);

        close(STDOUT_FILENO);
        dup(pipefd2[1]);
        
        close(pipefd2[1]);

        if (execlp("grep", "grep", ".c", NULL) == -1)
        {
            perror("exec grep");
            return - 1;
        }
    }
    // waitpid(pid, NULL, 0);
    close(pipefd2[1]);

    close(STDIN_FILENO);
    dup(pipefd2[0]);

    close(pipefd2[0]);
    if (execlp("cowsay", "cowsay", NULL) == -1)
    {
        perror("exec cowsay");
        return 1;
    }
    return 0;
}
