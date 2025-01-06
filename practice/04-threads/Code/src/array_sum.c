#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000
#define NUM_THREADS 4

int array[ARRAY_SIZE];
long long global_sum = 0;
pthread_mutex_t sum_mutex;

void* calculate_sum(void* arg) {
    int thread_id = *(int*)arg;
    free(arg);
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    long long local_sum = 0;
    for (int i = start; i < end; i++) {
        local_sum += array[i];
    }

    pthread_mutex_lock(&sum_mutex);
    global_sum += local_sum;
    pthread_mutex_unlock(&sum_mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&sum_mutex, NULL);

    // initialize array values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, calculate_sum, thread_id);
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total Sum: %lld\n", global_sum);

    pthread_mutex_destroy(&sum_mutex);
    return 0;
}
