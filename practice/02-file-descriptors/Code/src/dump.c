#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 5

void dump(const char *filename, int *array, size_t size) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    ssize_t bytes_written;
    for (size_t i = 0; i < size; ++i) {
        bytes_written = write(fd, &array[i], sizeof(int));
        if (bytes_written == -1) {
            perror("Error writing to file");
            close(fd);
            exit(1);
        }
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file path>\n", argv[0]);
        exit(1);
    }

    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 6};

    char *filename = argv[1];

    dump(filename, arr, ARRAY_SIZE);

    printf("Data dumped!\n");

    return 0;
}
