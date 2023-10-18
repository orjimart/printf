#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: strintg to be formatted
 * Return: return the exact strings produced
 */
int _printf(const char *format, ...)
{
	unsigned int mart = 0, a, enumerate = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
		our_putchar(format[a]);
		}
		else if (format[a] == '%' && format[a + 1] == 'c')
		{
			our_putchar(va_arg(args, int));
			a++;
		}
		else if (format[a] == '%' && format[a + 1] == 's')
			{
			enumerate = di_puts(va_arg(args, char *));
			mart += (enumerate - 1);
			a++;
			}
		else if (format[a] == '%' && (format[a + 1] == '%'))
			{
			our_putchar('%');
			a++;
			}
		else
		{
		our_putchar('%');
		}
		mart += 1;
	}
		va_end(args);
		return (mart);
}

/**
 * printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

		if (format[i] != '%')
		{
			our_putchar(format[i]);
			printed_chars++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int num = va_arg(args, int);
			printed_chars += di_prints(num);
			i++;
		}
		else
		{
			our_putchar('%');
			printed_chars++;
		}
		i++;
	
	va_end(args);
	return (printed_chars);
}
