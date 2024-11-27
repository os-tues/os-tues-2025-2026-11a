#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 5

void load(const char *filename, size_t size) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        exit(1);
    }

    int value;
    ssize_t bytes_read;
    for (size_t i = 0; i < size; ++i) {
        bytes_read = read(fd, &value, sizeof(int));
        if (bytes_read == -1) {
            perror("Error reading from file");
            close(fd);
            exit(1);
        } else if (bytes_read == 0) {
            break;
        }
        printf("Integer %zu: %d\n", i + 1, value);
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file path>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    printf("\nLoading data:\n");
    load(filename, ARRAY_SIZE);

    return 0;
}
