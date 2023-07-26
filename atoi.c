#include "main.h"

/**
 * _atoi - convert string to integer
 * @a: input string
 * Return: converted intger value
 */
int _atoi(const char *a)
{
	int r = 0; /*result*/
	bool n = false; /* if it's negtive number or not*/

	while (*a == ' ' || *a == '\t' || *a == '\n' || *a == '\r'
			|| *a == '\v' || *a == '\f')
		a++;

	/* checking the sign*/
	if (*a == '-')
	{
		n = true;
		a++;
	}
	else if (*a == '+')
		a++;

	/*now let's convert*/
	while (*a >= '0' && *a <= '9')
	{
		r = r * 10 + (*a - '0');
		a++;
	}

	if (n)
		r = -r;/*if negtaive*/

	return (r);
}
