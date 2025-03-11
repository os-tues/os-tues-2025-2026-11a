#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DIR *dir = opendir(argv[1]);
    if (!dir) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    printf("Inode       Type       Name\n");
    printf("------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        printf("%-10lu ", entry->d_ino);  // Print inode number

        // Print file type
        switch (entry->d_type) {
            case DT_REG:  printf("File      "); break;
            case DT_DIR:  printf("Directory "); break;
            case DT_LNK:  printf("Symlink   "); break;
            case DT_BLK:  printf("Block Dev "); break;
            case DT_CHR:  printf("Char Dev  "); break;
            case DT_FIFO: printf("FIFO      "); break;
            case DT_SOCK: printf("Socket    "); break;
            default:      printf("Unknown   "); break;
        }

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
