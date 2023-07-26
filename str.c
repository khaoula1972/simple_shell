#include "main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: pointer to string destination
 * @src: pointer to the soucrce
 * Return: pointer to the dest string
 */
char *_strcat(char *dest, const char *src)
{
	char *end = dest;

	/* find end */
	while (*end != '\0')
	{
		end++;
	}

	/* append source string to dest */
	while (*src != '\0')
	{
		*end = *src;
		end++;
		src++;
	}

	*end = '\0'; /* Null terminated */

	return (dest);
}

/**
 * _strchr - a function that find the first occurnce of a character in string
 * @str: the string
 * @c: the caractere
 * Return: pointer to first occurence Null if not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	/* if not found NULL*/
	return (NULL);
}


/**
 * _strcmp - function for string comparison
 * @str1: Pointer to the first string
 * @str2: Pointer to the second string
 * Return: negative if str1 is less than str 2, vice versa, 0 if equal
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strcpy - Copy a string from source to dest
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}


/**
 * _strcspn - calculates the length of the initial substring
 * in the str that does not contain any char from reject
 * @str: pointer str
 * @reject: pointer to reject
 *
 * Return: length of the initial substring in the str
 * that does not contain any characters from the reject
 */

size_t _strcspn(const char *str, const char *reject)
{
	size_t cnt = 0;
	const char *r; /* Pointer to traverse the reject str */

	while (*str)
	{
		/* Reset r to the beginning of the 'reject' for each char in 'str */
		r = reject;

		while (*r)
		{
			if (*str == *r)
				return (cnt);
			r++;
		}
		str++;
		cnt++;
	}

	return (cnt);
}

