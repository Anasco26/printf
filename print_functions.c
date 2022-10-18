#include "main.h"
#include <stdio.h>

/**
 * print_char - fn to print char
 * @arg: 
 */

void (*_print_char)(va_list args)
{
	return (_putchar(va_arg(args, int)));
}
