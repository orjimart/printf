#include "main.h"

/**
 * di_prints - this prints integer
 *
 * @in: inputs any number
 * Return: int
 */

int di_prints(int in)
{
	int no = 0;

	if (in < 0)
	{
		no += our_putchar('-');
		in = -in;
	}
	if (in / 10 != 0)
	{
		no += di_prints(in / 10);
	}
	no += our_putchar('0' + (in % 10));
	return (no);
}
