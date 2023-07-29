#include "main.h"

/**
 * unalias - sets alias to string
 * @function_args: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unalias(function_args *function_args, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = dni(&(function_args->alias_node),
		gni(function_args->alias_node, nsw(function_args->alias_node, str, -1)));
	*p = c;
	return (ret);
}

/**
 * salias - sets alias to string
 * @function_args: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int salias(function_args *function_args, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unalias(function_args, str));

	unalias(function_args, str);
	return (ane(&(function_args->alias_node), str, 0) == NULL);
}

/**
 * palias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int palias(string_list *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->string, '=');
		for (a = node->string; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - mimics the alias builtin (man alias)
 * @function_args: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _alias(function_args *function_args)
{
	int i = 0;
	char *p = NULL;
	string_list *node = NULL;

	if (function_args->arg_count == 1)
	{
		node = function_args->alias_node;
		while (node)
		{
			palias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; function_args->arg_vector[i]; i++)
	{
		p = _strchr(function_args->arg_vector[i], '=');
		if (p)
			salias(function_args, function_args->arg_vector[i]);
		else
			palias(nsw(function_args->alias_node,
						function_args->arg_vector[i], '='));
	}

	return (0);
}

