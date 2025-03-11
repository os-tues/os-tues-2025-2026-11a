#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dirName = argv[1];

    if (mkdir(dirName, 0755) == 0) {
        printf("Directory '%s' created successfully.\n", dirName);
    } else {
        perror("mkdir failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
