#include "main.h"

/**
  * print_string - a function that prints a string
  * @str: the string to be printed
  * Return: string else error
  */

void print_string(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
