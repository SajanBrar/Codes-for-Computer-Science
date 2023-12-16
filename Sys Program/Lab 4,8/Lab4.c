#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    // File descriptor for the new file
    int fd;
    // Create a new file or open an existing one (if it exists)
    // The file will be created with read and write permissions (0644)
    fd = open("Lab4.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }
    // Write a string to the file
    char *text = "Hello, UNIX System Calls!\n";
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1)
    {
        perror("write");
        close(fd);
        exit(1);
    }
    // Close the file close(fd);
    printf("File 'example.txt' created and written successfully.\n");
    return 0;
}