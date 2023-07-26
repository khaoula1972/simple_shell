#include "main.h"

/**
 * _strdup - duplicate string in memory
 * @str: string to be duplicated
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	size_t i, len = 0;
	const char *s = str;
	char *dup;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	dup = (char *)malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i]; /*copy characters*/

	dup[len] = '\0'; /* NULL terminator*/

	return (dup);
}

/**
 * _strlen - function that counts the length of a string
 * @s: the given string
 * Return: length of the string
 */
size_t _strlen(const char *s)
{
	size_t l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}


/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: max num of bytes from src
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, size_t n)
{
	size_t i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strncmp - compare first n chars of two strings
 * @s1: The first string
 * @s2: the second string
 * @n: max num of chars
 * Return: an integer value if great than 0 first n chars of s1 found to be
 * less thann first chars of s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}


/**
 * _strncpy - copies a string
 * @dest: destination string to be copied to
 * @src: source string
 * @n: num of chars to be copied
 * Return: concatenated string
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
