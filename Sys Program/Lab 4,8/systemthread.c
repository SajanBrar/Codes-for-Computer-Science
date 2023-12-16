/*
The POSIX Threads, or pthreads, is a threading library for 
Unix-like operating systems, providing a way to create and manage 
multiple threads within a program. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function that each thread will execute
void *threadFunction(void *threadId) {
    long tid = (long)threadId;
    printf("Hello, I am thread #%ld!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void *)t);
        
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed.\n");
    pthread_exit(NULL);
    return 0;
}

/*
Include necessary headers: `pthread.h` is required to use pthread functions.
Define the thread function: In this case, `threadFunction` is the function each thread will execute. It takes a `void*` argument, which can be used to pass any necessary data to the thread.
Main function: 
    - `pthread_t threads[NUM_THREADS];` creates an array of pthreads.
    - `pthread_create` creates threads, passing in the thread ID, attributes (set to `NULL` for default), the function to execute, and any arguments for that function.
    - `pthread_join` waits for threads to finish executing before the program continues.
    - Finally, it prints a message when all threads have completed and exits.
*/

// Another Example

// #include <stdio.h>
// #include <pthread.h>

// void *thread_function(void *arg) {
//     printf("Thread is running\n");
//     return NULL;
// }

// int main() {
//     pthread_t thread_id;
//     int ret;

//     ret = pthread_create(&thread_id, NULL, thread_function, NULL);
//     if (ret != 0) {
//         fprintf(stderr, "Error creating thread\n");
//         return 1;
//     }

//     pthread_join(thread_id, NULL); // Wait for the thread to finish
//     return 0;
// }

// /*
// pthread_create() creates a new thread executing thread_function.
// pthread_join() waits for the thread to finish execution before continuing in the main thread.
// */