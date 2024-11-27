#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 5

void load(const char *filename, size_t size) {

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
