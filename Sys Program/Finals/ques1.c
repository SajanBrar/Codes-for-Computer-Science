#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent process (PID: %d)\n", getpid());

    pid = fork(); 

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child process (PID: %d), Parent PID: %d\n", getpid(), getppid());
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process, waiting for child (PID: %d) to finish...\n", pid);
        wait(NULL); 
        printf("Child process (PID: %d) has finished.\n", pid);
        printf("Parent process exiting.\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}
