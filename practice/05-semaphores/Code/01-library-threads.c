#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define READERS_COUNT 20
#define READER_THREADS_TO_START 30

typedef struct {
    sem_t *sem_readers;
    int id;
} thread_data_t;

void *read_and_print_file(void *arg);

int main() {
    sem_t *sem_readers = sem_open("library_readers", O_CREAT | O_RDWR, 0664, READERS_COUNT);
    if (sem_readers == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    pthread_t threads[READER_THREADS_TO_START];
    thread_data_t thread_data[READER_THREADS_TO_START];

    for (int i = 0; i < READER_THREADS_TO_START; i++) {
        thread_data[i].sem_readers = sem_readers;
        thread_data[i].id = i;

        if (pthread_create(&threads[i], NULL, read_and_print_file, &thread_data[i]) != 0) {
            perror("pthread_create");
        }
    }

    for (int i = 0; i < READER_THREADS_TO_START; i++) {
        pthread_join(threads[i], NULL);
    }

    if (sem_close(sem_readers) == -1) {
        perror("sem_close");
    }

    return 0;
}

void *read_and_print_file(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    sem_t *sem_readers = data->sem_readers;
    int id = data->id;

    if (sem_wait(sem_readers) == -1) {
        perror("sem_wait");
        return NULL;
    }

    // Start of readers critical section
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
    }

    char out_name[] = "out/A.txt";
    out_name[4] = 'A' + id;
    int fd_out = open(out_name, O_WRONLY | O_CREAT, 0666);
    if (fd_out == -1) {
        perror("open fd_out");
    }

    unsigned char buff[10];
    int read_return;
    while ((read_return = read(fd, buff, 10)) > 0) {
        if (write(fd_out, buff, read_return) == -1) {
            perror("write");
        }
    }

    if (read_return == -1) {
        perror("read");
    }

    if (close(fd) == -1) {
        perror("close");
    }
    if (close(fd_out) == -1) {
        perror("close");
    }

    // End of readers critical section

    if (sem_post(sem_readers) == -1) {
        perror("sem_post");
    }

    return NULL;
}
