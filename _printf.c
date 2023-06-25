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
	int q;
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
				case 'd' ||'i' :
					q = va_arg(list_args, int);
					count += print_int(q);
					break;

				case 'b' : 
					q = va_arg(list_args, int);
					print_binary (q);
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

/**
 * print_int- print number
 * @number: the number
 * Return: the number of words
 */
int print_int (int number){ 

	int count = 0;
	printf("%d", number);
		
	if (number == 0)

		count++;
	else if (number < 0)
		count++;
	while (number != 0){
		number /= 10;
		count++;
	    	}
	
	return (count);
}


/**
 * print_binary- print binary
 * @number: the number
 * Return: void
 */
void print_binary(int number){

	int x, y;
	int arr[33];

	x=0;
	while (number > 0)
	{
		arr[x] = (number % 2);
		number /= 2;
		x++;
	}
	y = x - 1;

	while (y >= 0){	
		printf("%d", arr[y]);
		y--;
	}	



}	
