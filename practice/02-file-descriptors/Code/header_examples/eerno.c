#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("nonexistent.txt", O_RDONLY);
    if (fd == -1) {
        perror("Грешка при отваряне на файл");
        printf("Код на грешката: %d\n", errno);
    }
    return 0;
}
