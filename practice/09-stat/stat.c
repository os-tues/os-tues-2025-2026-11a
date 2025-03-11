#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>


// struct stat {
//     dev_t     st_dev;     // ID of device containing file
//     ino_t     st_ino;     // Inode number
//     mode_t    st_mode;    // File type and mode (permissions)
//     nlink_t   st_nlink;   // Number of hard links
//     uid_t     st_uid;     // User ID of owner
//     gid_t     st_gid;     // Group ID of owner
//     dev_t     st_rdev;    // Device ID (if special file)
//     off_t     st_size;    // File size in bytes
//     blksize_t st_blksize; // Block size for I/O
//     blkcnt_t  st_blocks;  // Number of 512B blocks allocated
//     time_t    st_atime;   // Last access time
//     time_t    st_mtime;   // Last modification time
//     time_t    st_ctime;   // Last status change time
// };


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    printf("File: %s\n", argv[1]);
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);
    printf("Blocks: %lld\n", (long long) fileStat.st_blocks);
    printf("Inode: %llu\n", (unsigned long long) fileStat.st_ino);
    printf("Mode: %o (octal)\n", fileStat.st_mode);
    printf("Hard Links: %lu\n", fileStat.st_nlink);
    printf("Owner UID: %u\n", fileStat.st_uid);
    printf("Group GID: %u\n", fileStat.st_gid);
    printf("Last access time: %s", ctime(&fileStat.st_atime));
    printf("Last modification time: %s", ctime(&fileStat.st_mtime));
    printf("Last status change time: %s", ctime(&fileStat.st_ctime));

    return EXIT_SUCCESS;
}
