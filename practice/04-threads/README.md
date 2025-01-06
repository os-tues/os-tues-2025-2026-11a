# Работа с нишки


1. Нишки
    - Съвременните операционни системи поддържат изпълнението на много нишки в рамките на един процес.
    - Нишкитена един процес се изпълняват паралелно.
    - Всички нишкина един и същ процес споделят: 
        - Код на програмата.
        - Глобални променливи.
        - Оперативна памет (Heap).
        - Отворенифайловеи ресурси.
        - Всяка нишка има собствен стек и програмен брояч

2. Key Functions for Working with Threads
    - pthread_create() – Creates a new thread.
    - pthread_join() – Waits for a thread to finish.
    - pthread_exit() – Terminates a thread.
    - pthread_mutex_init() – Initializes a mutex for synchronization.
    - pthread_mutex_lock() – Locks a mutex to ensure thread-safe access.
    - pthread_mutex_unlock() – Unlocks a mutex.
    - pthread_mutex_destroy() – Frees resources used by the mutex.

3. int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void*(*start_routine)(void *), void *arg);
    - thread: Pointer to thread ID.
    - attr: Thread attributes (can be NULL for default).
    - start_routine: Function to execute in the thread.
    - arg: Argument passed to start_routine.
    - Returns: 0 on success, non-zero on failure.

4. int pthread_join(pthread_t thread, void **retval);
    - thread: ID of the thread to wait for.
    - retval: Pointer to where the thread's return value is
    stored.
    - Returns: 0 on success, non-zero on failure.

5. void pthread_exit(void *retval);
    - retval: Return value of the thread.

6. int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    - mutex: Mutex to initialize.
    - attr: Mutex attributes (NULL for default).
    - Returns: 0 on success, non-zero on failure.

7. int pthread_mutex_lock(pthread_mutex_t *mutex);
    - mutex: Mutex to lock.
    - Returns: 0 on success, non-zero on failure.

8. int pthread_mutex_unlock(pthread_mutex_t *mutex);
    - mutex: Mutex to unlock.
    - Returns: 0 on success, non-zero on failure.

9. int pthread_mutex_destroy(pthread_mutex_t *mutex);
    - mutex: Mutex to destroy.
    - Returns: 0 on success, non-zero on failure.

10. Задачи

    - Increment Counter with Mutex: Use pthread_create to create a thread that increments a shared counter.Use a mutex to prevent race conditions. Observe the output with and without the mutex.
    - Simulate Bank Transactions: Create two threads: one for deposits, one for withdrawals.Use a shared balance variable protected by a mutex.Simulate 50,000 deposit and withdrawal transactions.
    - Split a large array into parts and calculate the sum using multiple threads.