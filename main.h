#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/**
 * struct fmt - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @fmt: The format specifier.
 * @fn: Pointer to the correct format specifier function.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list);
} fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *ind, va_list list);

int _putchar(char c);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_unsigned(va_list args);


#endif

