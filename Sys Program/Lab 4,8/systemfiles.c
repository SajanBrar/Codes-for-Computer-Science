/*
In C, the `open`, `read`, and `write` functions are used to 
work with files in Unix-like operating systems. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_descriptor;
    ssize_t num_bytes;
    char buffer[100];

    // Open a file in read-only mode
    file_descriptor = open("example.txt", O_RDONLY);
    if (file_descriptor == -1) {
        perror("open");
        return 1;
    }

    // Read from the file
    num_bytes = read(file_descriptor, buffer, sizeof(buffer));
    if (num_bytes == -1) {
        perror("read");
        close(file_descriptor);
        return 1;
    }

    // Display the content read from the file
    printf("Read %zd bytes: \n", num_bytes);
    write(STDOUT_FILENO, buffer, num_bytes);

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}

/*
`open()`: Opens a file and returns a file descriptor (an integer representing the file). In this example, it tries to open a file named `example.txt` in read-only mode using `O_RDONLY` flag.
`read()`: Reads data from the file associated with the file descriptor. It takes the file descriptor, a buffer to store the read data, and the number of bytes to read. In this case, it reads up to `sizeof(buffer)` bytes from the file into the `buffer`.
`write()`: Writes data to the specified file descriptor. In this case, it writes the content read from the file (stored in `buffer`) to the standard output (`STDOUT_FILENO`).
`close()`: Closes the file associated with the file descriptor. It's good practice to close files after using them to free up system resources.
*/