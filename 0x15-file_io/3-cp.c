#include <stdio.h>
#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


void cp(char *file_from, char *file_to);

void _error(int e, char *filename);

/**
 * main - check whether the number of argument is the correct one
 * @ac: count the arguments
 * @av: check the argument values
 * Return: if yes, 0, else, exits with error code 97.
 */
int main(int ac, char *av[])
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	cp(av[1], av[2]);
	return (0);
}

/**
 * cp - Function that copies the content of a file to another file.
 * @file_from: source, we copy from
 * @file_to: we paste content here
 * Return: 1 on success, -1 on failure.
 */
void cp(char *file_from, char *file_to)
{
	int fd_read, n_read, fd_write, n_write;
	int c_flag = 1;
	char buf[1024];

	/* READ */
	fd_read = open(file_from, O_RDONLY);
	if (fd_read < 0)
		_error(98, file_from);
	/* WRITE */
	fd_write = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_write < 0)
	{
		close(fd_read);
		_error(99, file_to);
	}
	do {
		/* READ */
		n_read = read(fd_read, buf, 1024);
		if (n_read < 0)
			_error(98, file_from);
		/* WRITE */
		n_write = write(fd_write, buf, n_read);
		if (n_write < n_read)
			_error(99, file_to);
	} while (n_write == 1024);
	if (close(fd_read) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_read);
		c_flag = 0;
	}
	if (close(fd_write) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_write);
		c_flag = 0;
	}
	if (!c_flag)
		exit(100);
}

/**
 * _error - Read file.
 * @e: Error number
 * @filename: File name
 */
void _error(int e, char *filename)
{
	if (e == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	if (e == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
