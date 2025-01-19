#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int main() {
    sem_t sem_bobcho;

    if (sem_init(&sem_bobcho, 0, 10) == -1) {
        perror("sem_init");
        return 1;
    }
    if (sem_wait(&sem_bobcho) == -1) {
        perror("sem_wait");
        return 1;
    }

    sleep(10);

    if (sem_post(&sem_bobcho) == -1) {
        perror("sem_post");
        return 1;
    }

    if (sem_destroy(&sem_bobcho) == -1) {
        perror("sem_destroy");
        return 1;
    }

    return 0;
}
