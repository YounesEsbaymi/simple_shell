#include "shell.h"

char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;
	int result = 0;

	for (i = 0; i < n; i++)
	{
		char ch1 = str1[i];
		char ch2 = str2[i];

		if (ch1 != ch2)
		{
			result = (int)(unsigned char)ch1 - (int)(unsigned char)ch2;
			break;
		}

		if (ch1 == '\0')
		{
			break;
		}
	}

	return (result);
}

int _snprintf(char *str, size_t size, const char *format, ...)
{
	int written = 0, remaining;
	va_list args;
	va_start(args, format);
	remaining = size - 1;

	while (*format != '\0' && remaining > 0)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					{
						int value = va_arg(args, int);
						char int_str[20];
						int digits = my_itoa(int_str, value);

						if (digits < 0)
						{
							va_end(args);
							return (-1);
						}
						if (digits > remaining)
						{
							va_end(args);
							return (-1);
						}
						_strcpy(str + written, int_str);
						written += digits;
						remaining -= digits;
						break;
					}
				case 's':
					{
						char *value = va_arg(args, char *);
						int length = _strlen(value);

						if (length > remaining)
						{
							va_end(args);
							return (-1);
						}
						_strcpy(str + written, value);
						written += length;
						remaining -= length;
						break;
					}
				default:
					va_end(args);
					return (-1);
			}
		}
		else
		{
			str[written] = *format;
			written++;
			remaining--;
		}
		format++;
	}
	str[written] = '\0';
	va_end(args);
	return (written);
}
int my_itoa(char *str, int num)
{
	int digits = 0;
	int temp = num;
	int i;

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	for (i = digits - 1; i >= 0; i--)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	str[digits] = '\0';
	return (digits);
}
