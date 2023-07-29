#include "main.h"

/**
 * list_len - determines length of linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */

size_t list_len(const string_list *head)
{
	size_t i = 0;

	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strs - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **list_to_strs(string_list *head)
{
	string_list *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->string) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->string);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * p_ls - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */

size_t p_ls(const string_list *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->number, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->string ? head->string : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * nsw - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

string_list *nsw(string_list *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = sw(node->string, prefix);
		if (p && ((c == -1) || (*p == c)))
		return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * gni - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t gni(string_list *head, string_list *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
		return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
