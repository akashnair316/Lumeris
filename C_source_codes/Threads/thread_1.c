#include <stdio.h>
#include <pthread.h>

// The simplest thread function signature required by pthreads
void* odd(void* arg) {
    while (1) {
        printf("Odd Thread running\n");
    }
    return NULL;
}

void* even(void* arg) {
    while (1) {
        printf("Even Thread running\n");
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create two threads with default attributes and no arguments
    pthread_create(&t1, NULL, odd, NULL);
    pthread_create(&t2, NULL, even, NULL);

    // Wait for both to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
