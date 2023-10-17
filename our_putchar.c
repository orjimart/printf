#include "main.h"
/**
 * our_putchar - prints a character
 *
 * @cha: inputs character
 * Return: 1
 */
int our_putchar(char cha)
{
	return (write(1, &cha, 1));
}
