#ifndef PROTOTYPES
#define PROTOTYPES
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_string(char *s);
int print_char(char c);
int print_int (int number);
void print_binary(int number);
#endif
