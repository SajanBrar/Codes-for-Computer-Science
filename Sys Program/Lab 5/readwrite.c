#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }
    // Process data in buffer
    close(fd);
    return 0;
}
