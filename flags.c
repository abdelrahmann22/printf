#include "main.h"

/**
 * get_specif - gets the specifier
 * @s: string to check
 * 
 * Return: bytes number printed
*/

int (*get_specif(char *s)) (va_list args, params_t *params)
{
	int i = 0;
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_str},
		//{"d", print_int},
		//{"i", print_int},
		{"b", print_bin},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_hexC},
		{"R", print_rev},
		{"r", print_r13},
		{"S", print_S},
		{"p", print_ptr},
		{"%", print_perc},
		{NULL, NULL}
	};

	while (specifiers[i].specifier)
	{
		if (*s == *specifiers[i].specifier)
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - gets the print function
 * @s: string to check
 * @args: arguments
 * @params: parameters
 * 
 * Return: bytes number printed
*/

int get_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *);

	f = get_specif(s);
	if (f)
		return (f(args, params));
	return (0);
}

/**
 * get_flag - gets the flag
 * @s: string to check
 * @params: parameters
 * 
 * Return: 1 if flag found, 0 otherwise
*/

int get_flag(char *s, params_t *params)
{
	if (*s == '#')
		params->hashtag = 1;
	else if (*s == '0')
		params->zero = 1;
	else if (*s == '-')
		params->minus = 1;
	else if (*s == '+')
		params->plus = 1;
	else if (*s == ' ')
		params->space = 1;
	else
		return (0);
	return (1);
}

/**
 * get_modifier - gets the modifier
 * @s: string to check
 * @params: parameters
 * 
 * Return: 1 if modifier found, 0 otherwise
*/

int get_modifier(char *s, params_t *params)
{
	if (*s == 'h')
		params->h_mod = 1;
	else if (*s == 'l')
		params->l_mod = 1;
	else
		return (0);
	return (1);
}

/**
 * get_width - gets the width
 * @s: string to check
 * @params: parameters
 * @args: arguments
 * 
 * Return: string
*/

char *getwidth(char *s, params_t *params, va_list args)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(args, int);
		s++;
	}
	else
	{
		while (*s >= '0' && *s <= '9')
		{
			x = x * 10 + (*s - '0');
			s++;
		}
	}
	params->width = x;
	return (s);
}
