#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
*/

int _putchar(char c)
{
	char buff[BUFFER_SIZE];
	int i;

	if (c == -1 || i >= BUFFER_SIZE)
	{
		write(1, &buff, i);
		i = 0;
	}
	if (c != -1)
	{
		buff[i] = c;
		i++;
	}
	return (1);
}
