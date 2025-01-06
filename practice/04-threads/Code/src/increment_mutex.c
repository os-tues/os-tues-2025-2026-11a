#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *increment_count(void *args);

pthread_mutex_t count_mutex;

int main()
{
    pthread_t thread1;
    pthread_mutex_init(&count_mutex, NULL);

    int count = 0;
    void *args = {&count};

    if (pthread_create(&thread1, NULL, increment_count, args) != 0) {
        printf("pthread_create() error\n");
        return 1;
    }
    increment_count(&count);
    printf("Before join :%d\n", count);
    pthread_join(thread1, NULL);
    printf("Count - %d\n", count);

    pthread_mutex_destroy(&count_mutex);
    return 0;
}

void *increment_count(void *args) {
    int *count = args;
    
    for (size_t i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&count_mutex);
        (*count)++;
        pthread_mutex_unlock(&count_mutex);
    }
    return (void *) 0;
}