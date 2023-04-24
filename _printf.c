#include "main.h"

/**
 * _printf - prints numbers and strings
 * @format: Format string
 * Return: bytes number printed
*/

int _printf(const char *format, ...)
{
	int counter = 0;
	va_list args;
	char *ptr, *st;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for(ptr = (char *)format; *ptr; ptr++)
	{
		init_param(&params, args);
		if(*ptr != '%')
		{
			counter += _putchar(*ptr);
			continue;
		}
		st = ptr;
		ptr++;
		while (get_flag(ptr, &params))
		{
			ptr++;
		}
		ptr = getwidth(ptr, &params, args);
		ptr = get_precision(p, &params, args);

	}	
}
