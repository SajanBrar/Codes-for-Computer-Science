#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open source file for reading
    source_fd = open("source.txt", O_RDONLY);
    if (source_fd == -1) {
        perror("open source.txt");
        return EXIT_FAILURE;
    }

    // Open destination file for writing
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open destination.txt");
        close(source_fd);
        return EXIT_FAILURE;
    }

    // Read from source and write to destination
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write error");
            close(source_fd);
            close(dest_fd);
            return EXIT_FAILURE;
        }
    }

    // Check for read error
    if (bytes_read == -1) {
        perror("read error");
        close(source_fd);
        close(dest_fd);
        return EXIT_FAILURE;
    }

    // Close files
    close(source_fd);
    close(dest_fd);

    printf("File copied successfully!\n");
    return EXIT_SUCCESS;
}