#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        // Child process
        printf("Child process\n");
        return 42;
    }
    else if (child_pid > 0)
    {
        int status;
        wait(&status);
        if (WIFEXITED(status))
        {
            printf("Child exit status: %d\n", WEXITSTATUS(status));
        }
    }
    else
    {
        perror("fork");
    }
    return 0;
}