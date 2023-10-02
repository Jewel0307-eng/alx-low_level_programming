#include "main.h"

/**
 * read_and_print_text - Reads a text file and prints the specified number of letters.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to be printed.
 *
 * Return: The number of letters printed. If it fails, returns 0.
 */
ssize_t read_and_print_text(const char *filename, size_t letters)
{
    int fd;
    ssize_t nread, nwritten;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);

    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (!buf)
        return (0);

    nread = read(fd, buf, letters);
    nwritten = write(STDOUT_FILENO, buf, nread);

    close(fd);

    free(buf);

    return (nwritten);
}
