#include "main.h"

/**
  * _putchar - a function that prints characters to
  * stdout
  * @c: character to be printed
  * Return: characters to  be printed
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
