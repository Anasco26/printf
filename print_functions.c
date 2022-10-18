#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - fn to print char
 * @args: char argument passed
 */

void print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_str - fn to print string
 * @args: string argument
 * Return: char count
 */

int print_str(va_list args)
{
	int n;
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(nil)";
	else if (str == '\0')
		return (-1);
	for (n = 0; str[n]; n++)
		_putchar(str[n]);
	return (n);
}

/**
 * print unsigned
 * @args: int arguement
 * Return: unsigned int count 
 */

int print_unsigned(va_list args)
{
	int n = va_arg(arg, unsigned int);

	int divisor = 1; /*divisor to print the first digit*/
	int i; /*counter*/

	while (n / divisor > 9)
		divisor *= 10;
	while (divisor != 0)
	{
		i = i + _putchar(n / divisor + '0');
		n = n % divisor;
		divisor = divisor / 10;
	}
	return (i)
}
