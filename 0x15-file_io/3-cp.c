#include "main.h"

/**
* main - copies contents of one file to another.
* @ac: number of command line arguments
* @av: arguments
* Return: Always 0;
*/

int main(int ac, char **av)
{
	int fd, f_read, f_write;
	char buf[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to");
		exit(97);
	}
	if (av[1] == NULL)
	{
		dprintf(2, "Error: Can't read from file %s", av[1]);
		exit(98);
	}
	fd = open(av[1], O_RDONLY);
	f_read = read(fd, buf, 1024);
	if (f_read < 0)
	{
		dprintf(2, "Error: Can't read from file     %s", av[1]);
		exit(98);
	}
	close_file(fd);
	fd = open(av[2], O_CREAT | O_WRONLY |  O_TRUNC, 0664);
	if (fd < 0)
	{
		dprintf(2, "Error: Can't write to %s", av[2]);
		exit(99);
	}
	f_write = write(fd, buf, f_read);
	if (f_write < 0)
	{
		dprintf(2, "Error: Can't write to %s",     av[2]);
		exit(99);
	}
	close_file(fd);
	return (0);
}

/**
* close_file - closes a file
* @fd: file desciptor of file
* Return: 0 on success or -1 on failure
*/
int close_file(int fd)
{
	int f_close = close(fd);

	if (f_close < 0)
	{
		dprintf(2, ": Can't close fd %d", fd);
		exit(100);
	}
	return (f_close);
}