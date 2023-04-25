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
	params_t params = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;

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
		ptr = get_precision(ptr, &params, args);

		if(!get_specifier(ptr))
		{
			counter += print_from_to(st, ptr, params.l_mod || params.h_mod ? ptr - 1 : 0);
		}
		else
		{
			counter += get_print_func(ptr, args, &params);
		}
		_putchar(BUFF_FLUSH);
		va_end(args);
		return (counter);
	}	
}
