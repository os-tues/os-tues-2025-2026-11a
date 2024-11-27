#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, "Hello, World!\n", 14);
    close(fd);
    return 0;
}
