#include "main.h"
/**
 * _printf - A function that prints formatted output
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int char_count = 0;
    va_list arg_list;
    char *format_ptr, *start;
    param_t param = PARAMS_INIT;

    va_start(arg_list, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1);

    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    for (format_ptr = (char *)format; *format_ptr; format_ptr++)
    {
        init_param(&param, arg_list);
        if (*format_ptr != '%') /* Check for characters not starting with '%' */
        {
            char_count += our_putchar(*format_ptr);
            continue;
        }
        start = format_ptr;
        format_ptr++;
        while (get_flags(format_ptr, &param)) /* Handle flag characters */
        {
            format_ptr++;
        }
        format_ptr = _width(format_ptr, &param, arg_list);
        format_ptr = _precision(format_ptr, &param, arg_list);
        if (_modifier(format_ptr, &param))
            format_ptr++;
        if (!list_specifiers(format_ptr))
            char_count += print_from_to(start, format_ptr,
                param.l_modifier || param.h_modifier ? format_ptr - 1 : 0);
        else
            char_count += _print_functions(format_ptr, arg_list, &param);
    }

    _putchar(BUF_FLUSH);
    va_end(arg_list);

    return (char_count);
}

