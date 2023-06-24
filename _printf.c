#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - to print any inputs
 * @format:the format to know the output
 * @...: the all arguments
 * Return: the ouput as string char or anything
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list list_args;

	va_start(list_args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += print_char(va_arg(list_args, int));
					break;
				case 's':
					count += print_string((char *)va_arg(list_args, int*));
					break;
				case '%':
					count += print_char('%');
					break;
			}
		}
		else
		{
			count += print_char(*format);
		}
		format++;
	}
	va_end(list_args);
	return (count);
}
/**
 * print_char - print char
 * @c: the char
 * Return: 1
 */

int print_char(char c)
{
	putchar(c);
	return (1);
}
/**
 * print_string- print string
 * @s: the string
 * Return: the string
 */

int print_string(char *s)
{
	int string = 0;

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		string++;
	}
	return (string);
}


