#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
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

	nrd = read(fd, buf, letters);
	if (nrd == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	nwr = write(STDOUT_FILENO, buf, nrd);
	if (nwr == -1 || nwr != nrd)
	{
		close(fd);
		free(buf);
		return (0);
	}

	close(fd);
	free(buf);

	return (nwr);
}
