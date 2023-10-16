#include "main.h"

/**
 * di_puts - this print strings
 * @strng: string to be inputed
 *
 * Return: numbr of bytes of strng printed
 */

int di_puts(char *strng)
{
	int mart;

	for (mart = 0; strng[mart] != '\0'; mart++)
	{
		our_putchar(strng[mart]);
	}
	return (mart);
}
