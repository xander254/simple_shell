#include "main.h"
#include <string.h>

/**
  * string_rm_newline -  a function to remove the
  * new line character in a string.
  * @str1: the first string
  * @str2: the second string
  * Return: string 1 without newline
  */

ssize_t string_rm_newline(const char *str1, const char *str2)
{
	const char *str = str1;
	const char *n;

	while (*str)
	{
		for (n = str2; *n; n++)
		{
			if (*str == *n)
			{
				return (str - str1);
			}
		}
		str++;
	}
	return (str - str1);
}
