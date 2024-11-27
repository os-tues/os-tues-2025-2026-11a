#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[]) {
    
    if (argc != 2){
        printf("needs two arguments\n");
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);

    int res;
    char buf;

    while((res = read(fd, &buf, sizeof(char))) !=0){

        if(res == -1){
            perror("read()");
            close(fd);
            return -1;
        }

        //putchar(buf);
        printf("%c", buf);
        fflush(stdout);
        write(STDOUT_FILENO, &buf, sizeof(char));

    }

    if (close(fd) == -1){
        perror("close()");
        return -1;
    }

    return 0;

}