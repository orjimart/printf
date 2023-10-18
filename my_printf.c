#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0, i = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			our_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			our_putchar(va_arg(args, int));
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			while (*str)
			{
				our_putchar(*str);
				count++;
				str++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			our_putchar('%');
			count++;
			i++;
		}
		else
		{
			our_putchar('%');
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}
