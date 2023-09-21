#include "shell.h"
/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @str: The string to search.
 * @ch: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
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
/**
 * _strncmp - Compare at most the first n characters of two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer greater than, equal to, or less than 0, depending on
 * whether str1 is greater than, equal to, or less than str2, respectively.
 */
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
/**
 * _snprintf - Write formatted data to a string with a specified limit.
 * @str: The destination string.
 * @size: The maximum number of characters to write (including the null byte).
 * @format: The format string.
 *
 * Return: The number of characters written (excluding the null byte) or -1
 * in case of an error or if the output would be truncated.
 */
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
/**
 * my_itoa - Convert an integer to a string.
 * @str: The destination string to store the result.
 * @num: The integer to convert.
 *
 * Return: The number of digits in the converted integer.
 */
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
