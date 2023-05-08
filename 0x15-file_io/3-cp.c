#include "main.h"

/**
 * main - must copies the content of a file to another file
 * @argc: argument counter
 * @argv: argument vector
 * Return: 98 if argument number invalid
 **/

int main(int argc, char **argv)

{
	int st1, st2, r_count, w_count, src_fd, dest_fd;
	char buf[BUFSIZ];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]), exit(98);

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((r_count = read(src_fd, buf, BUFSIZ)) > 0)
	{
		w_count = write(dest_fd, buf, r_count);
		if (w_count != r_count)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (r_count == -1)
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]), exit(98);

	st1 = close(src_fd);
	if (st1 == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd), exit(100);

	st2 = close(dest_fd);
	if (st2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd), exit(100);

	return (0);
}
