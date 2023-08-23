#include "shell.h"

/**
 * _eputs - Prints the supplied string input
 * @str: The string meant for printing
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the char c to stderr
 * @c: Char to be printed
 *
 * Return: 1 on success .
 * On error, -1 is returned, and errno is set accordingly.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes The char c to given fd
 * @c: The char meant for printing
 * @fd: The file descriptor to which writing will be performed
 *
 * Return: 1 on success .
 * On error, -1 is returned, and errno is set accordingly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: The string meant to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters that were put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
