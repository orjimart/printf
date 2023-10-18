#include "main.h"

/**
 * _printf - Function that produces output according to a format.
 * @format: String to be formatted.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;
	unsigned int i = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				our_putchar(va_arg(args, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					our_putchar(*str);
					str++;
					count++;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				our_putchar('%');
				i++;
			}
			else
				our_putchar('%');
		}
		else
		{
			our_putchar(format[i]);
		}
		count++;
	}

	va_end(args);
	return (count);
}

