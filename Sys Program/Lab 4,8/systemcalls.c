/*
#include <bits/stdc++.h>
In C language, fork, exec, exit, and wait 
are system calls used for process management in Unix-like operating systems.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent process (PID: %d)\n", getpid());

    pid = fork(); // Create a new child process

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d), Parent PID: %d\n", getpid(), getppid());

        // Execute a command using exec
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args);

        // If execvp returns, it means an error occurred
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process, waiting for child (PID: %d) to finish...\n", pid);
        wait(NULL); // Wait for the child process to finish

        printf("Child process (PID: %d) has finished.\n", pid);
        printf("Parent process exiting.\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}

/*
fork(): Creates a new process by duplicating the calling process. After a successful fork(), two processes are running: the parent and the child. fork() returns the child's process ID to the parent and returns 0 to the child process.
if (pid < 0) { ... } else if (pid == 0) { ... } else { ... }: This conditional block is used to distinguish between the parent and child processes. The child process executes the code inside the else if (pid == 0) block while the parent process continues in the else block.
execvp(): Replaces the current process image with a new process image. In this example, it executes /bin/ls -l command. If successful, it won't return. If it fails, it prints an error using perror() and exits the child process with EXIT_FAILURE.
wait(): In the parent process, it waits for the child process to terminate. wait(NULL) suspends execution of the calling process until a child process finishes.
exit(): Terminates the process. The parent process exits after the child process finishes its execution.
*/