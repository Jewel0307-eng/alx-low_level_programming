#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print. If there are any errors,
 *         or if the file can't be opened or read, or if write fails, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
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
    {
        close(fd);
        return (0);
    }

    nread = read(fd, buf, letters);
    if (nread == -1)
    {
        close(fd);
        free(buf);
        return (0);
    }

    nwritten = write(STDOUT_FILENO, buf, nread);
    if (nwritten == -1 || (size_t)nwritten != (size_t)nread)
    {
        close(fd);
        free(buf);
        return (0);
    }

    close(fd);
    free(buf);

    return (nwritten);
}
