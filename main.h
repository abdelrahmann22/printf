#ifndef _MAIN_H_
#define _MAIN_H_

#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct specifier - struct for specifiers
 * @type: the type of specifier
 * @f: the function pointer to the correct specifier
*/
typedef struct specifier
{
	char *type;
	int (*f)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int (*get_specifier(char s))(va_list);
int print_md(const char *format, specifier_t *specifiers, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);
int print_S(va_list args);
int print_address(va_list args);
int print_percent(va_list args);
int _putchar(char c);
int _strlen(char *s);

#endif
