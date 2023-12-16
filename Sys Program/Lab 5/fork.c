#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        // This code is executed in the child process printf("Child
        ("process\n ");
    }
    else if (child_pid > 0)
    {
        // This code is executed in the parent process
        printf("Parent process\n");
    }
    else
    {
        perror("fork");
    }
    return 0;
}