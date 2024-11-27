#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return -1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open() source file");
        return -1;
    }

    int dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open() destination file");
        close(src_fd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) != 0) {
        if (bytes_read == -1) {
            perror("read()");
        }
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write()");
            close(src_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (close(src_fd) == -1) {
        perror("close() source file");
        return -1;
    }

    if (close(dest_fd) == -1) {
        perror("close() destination file");
        return -1;
    }

    printf("File copied successfully!\n");
    return 0;
}