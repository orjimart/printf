#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

int di_prints(int in);
int _printf(const char *format, ...);
int our_putchar(char cha);
int di_puts(char *strng);
int (*list_specifiers(char *strng))(va_list arg, param_t *param);
int _print_function(char *strng, va_list arg, param_t *param);
int _modifier(char *strng, param_t *param);
char *_width(char *strng, param_t *param, va_list arg);
#endif
