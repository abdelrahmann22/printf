#include "main.h"

/**
 * init_params - Reset Buff
 * @params: Parameters struct
 * @args: Argument Pointer
 * Return: Void
*/
void init_params(params_t *params, va_list args)
{
	params -> unsign = 0;
	params -> plus = 0;
	params -> space = 0;
	params -> hashtag = 0;
	params -> zero = 0;
	params -> minus = 0;
	params -> width = 0;
	params -> precision = UINT_MAX;
	params -> h_mod = 0;
	params -> l_mod = 0;

	(void)args; 
}
