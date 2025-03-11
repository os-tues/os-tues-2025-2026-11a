#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }

    const char *dirName = argv[1];

    int dir_fd = open("asd", O_RDONLY);
    if (dir_fd == -1) {
        perror("open");
        return 1;
    }

    if (mkdirat(dir_fd, dirName, 0755) == 0) {
        printf("Directory '%s' created successfully using mkdirat.\n", dirName);
    } else {
        perror("mkdirat failed");
    }

    close(dir_fd);
    return 0;
}
