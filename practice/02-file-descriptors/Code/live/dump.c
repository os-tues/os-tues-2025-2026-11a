#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 5

void dump(const char *filename, int *array, size_t size) {
    
    if(filename==NULL || array == NULL) return;
    int file = open(filename, O_WRONLY | O_CREAT);
    
    if(file == -1){
        perror("Error opening file");
        return;
    }

    int bytes_written;
    for (int i = 0; i<size; i++){
        bytes_written = write(file, &array[i], sizeof(int));
        if(file == -1){
            perror("Write error");
            close(file);
            return;
        }
    }
    close(file);
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