#include "main.h"

/**
 * list_specifiers - this list the function specifiers
 * @strng: string
 *
 * Return: No of bytes
 */

int (*list_specifiers(char *strng))(va_list arg, param_t *param)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	int vin = 0;

	while (specifiers[vin].specifier)
	{
		if (*strng == specifiers[vin].specifier[0])
		{
			return (specifiers[vin].f);
		}
		vin++;
	}
	return (NULL);
}

/**
 * _print_function - this gets the print functions
 * @strng: String
 * @arg: Argumnt pointers used
 *
 * @param:  Parameter struct used
 *
 * Return:  No of bytes
 */

int _print_function(char *strng, va_list arg, param_t *param)
{
	int (*f)(va_list, param_t *) = list_specifiers(s);

	if (f)
		return (f(arg, param));
	return (0);
}

/**
 * get_flags - this gets the flags
 * @strng: string
 * @param:  parameters struct used
 *
 * Return: if flag is active
 */

int get_flags(char *strng, param_t *param)

{
	int vin = 0;

	switch (*strng)
	{
		case '+':
			vin = param->plus_flag = 1;
			break;
		case ' ':
			vin = param->space_flag = 1;
			break;
		case '#':
			vin = param->hashtag_flag = 1;
			break;
		case '-':
			vin = param->minus_flag = 1;
			break;
		case '0':
			vin = param->zero_flag = 1;
			break;
	}
	return (vin);
}

/**
 * _modifier - this locates the modifier function
 * @strng: string
 *
 * @param: parameter struct
 *
 * Return: if modifier was active
 */

int _modifier(char *strng, param_t *param)
{
	int vin = 0;

	switch (*strng)
	{
		case 'h':
			vin = param->h_modifier = 1;
			break;
		case 'l':
			vin = param->l_modifier = 1;
			break;
	}
	return (vin);
}

/**
 * _width - width from the format string
 * @strng: string
 *
 * @param: parameters strucure
 * @arg: Argument pointer
 *
 * Return: fresh pointer
 */

char *_width(char *strng, param_t *param, va_list arg)

	/* should this function use character **s and modify the pointer? */
{
	int c = 0;

	if (*strng == '*')
	{
		c = va_arg(arg, int);
		strng++;
	}
	else
	{
		while (_isdigit(*strng))
		c = c * 10 + (*strng++ - '0');
	}
	param->width = c;
	return (strng);
}
