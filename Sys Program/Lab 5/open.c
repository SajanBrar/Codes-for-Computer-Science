#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    // Write and manipulate the file
    close(fd);
    return 0;
}
