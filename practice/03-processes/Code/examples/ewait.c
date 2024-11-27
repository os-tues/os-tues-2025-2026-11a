#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main() { 
    pid_t pid = fork(); 
    if (pid == 0) { 
         printf("Child process\n"); 
         return 42;
    } else { 
         int status; 
         wait(&status); 
         printf("Child status %d\n", WEXITSTATUS(status)); 
   } 
    return 0; 
}
