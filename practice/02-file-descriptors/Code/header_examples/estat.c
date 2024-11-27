#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat fileStat;
    if (stat("test.txt", &fileStat) == 0) {
        printf("File size: %ld bytes\n", fileStat.st_size);
    } else {
        perror("stat");
    }
    return 0;
}
