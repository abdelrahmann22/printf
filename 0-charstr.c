#include "main.h"


int print_char(va_list args)
{
	int c = va_arg(args, int);
	return (_putchar(c));
}

int print_str(va_list args)
{
	int i, counter = 0;
	const char *ptr	= va_arg(args, const char *);


	ptr = (ptr != NULL) ? ptr : "(null)";
	while(*ptr != '\0'){
		_putchar(*ptr++);
		counter++;
	}
	return (counter);
}
