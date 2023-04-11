#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @source_file: source_file.
 * @destination: destination.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_from, int destination, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (destination == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int source_file, destination, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp source_file destination");
		exit(97);
	}

	source_file = open(argv[1], O_RDONLY);
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(source_file, destination, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(source_file, buf, 1024);
		if (nchars == -1)
			error_file(-1, 0, argv);
		nwr = write(destination, buf, nchars);
		if (nwr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(source_file);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_file);
		exit(100);
	}

	err_close = close(destination);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_file);
		exit(100);
	}
	return (0);
}