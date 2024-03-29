#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
int counter = 0;

void *thread_function(void *arg) {
    pthread_mutex_lock(&mutex);  // Lock the critical section
    counter++;
    printf("Thread ID: %ld, Counter Value: %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&mutex);  // Unlock the critical section
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);  // Initialize the mutex

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);  // Destroy the mutex
    return 0;
}
