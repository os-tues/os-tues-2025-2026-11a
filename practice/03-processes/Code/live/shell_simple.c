#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char line[128];
    while(1){

        printf("shell> ");
        fgets(line, 128, stdin);
        char* p = strchr(line, '\n');
        if (p != NULL){
            *p = '\0';
        }
        //line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0){
            //CHILD
            int res = execlp(line, line, NULL);
            if(res <0){
                printf("Execution failed\n");
                return 1;
            }
        }
        else{
            //PARENT
            int status;
            wait(&status);
        }

    }

    return 0;
}