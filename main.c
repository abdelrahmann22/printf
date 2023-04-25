#include "main.h"

int main(void)
{
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	_printf("Hello World\n");
	_printf("Hello %s\n", "World");
	_printf("Hello %c\n", 'W');
	_printf("%r\n");
	_printf("%b\n", 98);
}
