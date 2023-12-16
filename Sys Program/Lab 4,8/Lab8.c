#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// Function to be executed by threads
void *threadFunction(void *arg)
{
    int thread_id = *((int *)arg);
    printf("Thread %d is running\n", thread_id);
    return NULL;
}
int main()
{
    // Creating a process
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process running\n");
        // Additional child process logic goes here
        exit(EXIT_SUCCESS);
    }
    else
    {
        // Parent process
        printf("Parent process waiting for child\n");
        // Wait for the child process to finish
        wait(NULL);
        printf("Parent process continuing after child\n");
        // Creating threads
        20124087 _ Sajanjit 51 | Page
                                         ITPC -
                                     425 System Programming Lab
                                         pthread_t thread1,
            thread2;
        int id1 = 1, id2 = 2;
        if (pthread_create(&thread1, NULL, threadFunction, (void *)&id1) != 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        if (pthread_create(&thread2, NULL, threadFunction, (void *)&id2) != 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        // Wait for threads to finish
        if (pthread_join(thread1, NULL) != 0)
        {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
        if (pthread_join(thread2, NULL) != 0)
        {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
        printf("Parent process exiting\n");
    }
    return 0;
}
