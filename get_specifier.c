#include "main.h"

/**
 * get_specifier - returns a function pointer to the correct specifier
 * @s: the specifier to check
 * Return: a function pointer to the correct specifier
*/
int (*get_specifier(char s))(va_list)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"b", print_binary},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{NULL, NULL}
	};
	int i;

	for (i = 0; specifiers[i].type != NULL; i++)
	{
		if (*(specifiers[i].type) == s)
			return (specifiers[i].f);
	}
	return (NULL);
}
