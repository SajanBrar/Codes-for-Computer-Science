#include <stdio.h>
#include <unistd.h>
int main()
{
    execl("/bin/ls", "ls", "-l", NULL);
    perror("exec");
    return 1; // Exec failed
}

// #include <stdio.h>

// int main() {
//     printf("This is the child program\n");
//     return 0;
// }
