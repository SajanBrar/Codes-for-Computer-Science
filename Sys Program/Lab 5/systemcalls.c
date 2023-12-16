#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;

    printf("Parent process (PID: %d)\n", getpid());

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (child_pid == 0)
    {
        // Inside the child process

        printf("Child process (PID: %d), Parent PID: %d\n", getpid(), getppid());

        // Execute the "ls" command in the child process
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl returns, it means it failed
        perror("execl failed");
        return 1;
    }
    else
    {
        // Inside the parent process

        printf("Parent process waiting for the child process (PID: %d) to finish...\n", child_pid);

        // Wait for the child process to terminate
        wait(NULL);

        printf("Parent process exiting...\n");
        exit(0); // Exit the parent process
    }

    return 0;
}