#include "main.h"

/**
 * print_char - fn to print char
 * @args: char argument passed
 *
 * Return: No. of printed chars
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
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
	for (n = 0; str[n] != '\0'; n++)
		_putchar(str[n]);
	return (n);
}

/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * Return: No. of sign printed
 */

int print_percent(va_list args)
{
	UNUSED(args);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print both decimal and integer num
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print unsigned - Prints an unsigned int
 * @args: int arguement
 * Return: unsigned int count
 */

int print_unsigned(va_list args)
{
	int n = va_arg(args, unsigned int);

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
	return (i);
}
