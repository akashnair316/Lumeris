#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_COUNT 20
#define ODD_EVEN_CHECK(n)   ((n) & 1U)


/* Shared Resources */
static volatile int g_counter = 0;
pthread_mutex_t lock;
pthread_cond_t cond;


void* print_even(void* arg) {

    while (1) {
        pthread_mutex_lock(&lock);

        if (g_counter >= MAX_COUNT) {
            pthread_mutex_unlock(&lock);
            break;
        }
        if((ODD_EVEN_CHECK(g_counter)) == 0) {
            printf("Even %d\n", g_counter);
            g_counter = g_counter + 1;
        }
        pthread_mutex_unlock(&lock);
        
    }
    return NULL;
}


void* print_odd(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        if (g_counter >= MAX_COUNT) {
            pthread_mutex_unlock(&lock);
            break;
        }
        if((ODD_EVEN_CHECK(g_counter)) == 1) {
            printf("ODD %d\n", g_counter);
            g_counter = g_counter + 1;
        }
        pthread_mutex_unlock(&lock);
        
    }
 
    return NULL;
}

int main(void) {
    pthread_t thread_odd, thread_even;

    /* 1. Initialize Primitives */
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }
    if (pthread_cond_init(&cond, NULL) != 0) {
        perror("Cond init failed");
        return 1;
    }

    /* 2. Create Threads */
    /* Note: Error checking omitted for brevity, but essential in production */
    pthread_create(&thread_even, NULL, print_even, NULL);
    pthread_create(&thread_odd, NULL, print_odd, NULL);

    /* 3. Wait for completion */
    pthread_join(thread_even, NULL);
    pthread_join(thread_odd, NULL);

    /* 4. Cleanup */
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    printf("Done.\n");
    return 0;
}