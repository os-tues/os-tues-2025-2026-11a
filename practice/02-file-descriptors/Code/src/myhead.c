#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINES 10

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open()");
        return -1;
    }

    char buf;
    int read_result;
    int line_count = 0;

    while ((read_result = read(fd, &buf, sizeof(char))) != 0) {
        if (read_result == -1) {
            perror("read()");
            close(fd);
            return -1;
        }
        write(STDOUT_FILENO, &buf, read_result);

        if (buf == '\n') {
            line_count++;
        }

        if (line_count >= MAX_LINES) {
            break;
        }
    }

    if (close(fd) == -1) {
        perror("close()");
        return -1;
    }

    return 0;
}