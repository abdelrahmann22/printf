#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * Struct params - Params struct
 * 
 * @unsign: Flag of unsigned value
 * @plus: Flag of plus specified
 * @space: Flag of hashtag specified
 * @hashtag: Flag of _flag specified
 * @zero: Flag of _flag specified
 * @minus: Flag of _flag specified
 * @width: Width specified
 * @precision: Precision specified
 * @h_mod: h_mod specified
 * @l_mod: l_mod specified
*/
typedef struct params
{
	unsigned int unsign :1;
	unsigned int plus : 1;
	unsigned int space : 1;
	unsigned int hashtag : 1;
	unsigned int zero : 1;
	unsigned int minus : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_mod : 1;
	unsigned int l_mod : 1;
}params_t

/**
 * struct speci - Struct token
 * 
 * @specifier: format token
 * @f: Function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
}specifier_t;
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);

#endif
