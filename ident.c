#include "main.h"
/**
 * is_inter - a function that returns if our shell is in interactive mode
 * @r: a struct addresse
 * Return: if interactive mode then 1, 0 if not
 */
int is_inter(function_args *function_args)
{
	return (isatty(STDIN_FILENO) && function_args->read_file_descriptor <= 2);
}

/**
 * _atoi - a func that convert string to integer
 * @str: the string we want to convert
 * Return: if numeber then converted integer, if not 0
 */
int _atoi(char *str)
{
	unsigned int res = 0;
	int i, integer;
	int s = 1, f = 0; /* sign and flag*/

	for (i = 0;  str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			f = 1; /* it's number */
			res = res * 10;
			res += (str[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (s == -1)
		integer = -res;
	else
		integer = res;
	return (integer);
}

/**
 * is_del - a function that checks if char is delimeter or not
 * @del: delimeter
 * @ch: the character we want to chack
 * Return: if it's delimeter then 1, 0 if not
 */
int is_del(char ch, char *del)
{
	while (*del)
	{
		if (*del++ == ch)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - function that checks for alphabet char
 * @ch: character we want to chcek
 * Return: 1 if it's an alphabet 0 if not
 */
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	return (0);
}
