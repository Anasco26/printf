#include <stdarg.h>

/**
 * print unsigned
 * @args: int arguement
 * Return: unsigned int count 
 */

int print_unsigned(const unsigned int w, ...)
{
	va_list num;
	int n = va_arg(arg, unsigned int);
	int m, rem;
	int divisor = 1; /*divisor to print the first digit*/
	int i; /*counter*/

	va_start(num, n);

	while (n / divisor > 9)
		divisor *= 10;
	while (divisor != 0)
	{
		i = i + _putchar(n / divisor + '0');
		n = n % divisor;
		divisor = divisor / 10;
	}

	va_end(num);

	return (i);
}

int main()
{
	int n;

	n = print_unsigned(2, 95, 88);
	printf("%d\n", n);
	return (0);
}
