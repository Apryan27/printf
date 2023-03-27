#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;

	va_start(args, format);
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while(*s)
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
