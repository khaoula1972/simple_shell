#include "main.h"

/**
 * get_environ - returns the string array copy of our environ
 * @function_args: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(function_args *function_args)
{
	if (!function_args->modified_environment
			|| function_args->environment_changed)
	{
		function_args->modified_environment =
			list_to_strs(function_args->environment_list);
		function_args->environment_changed = 0;
	}

	return (function_args->modified_environment);
}

/**
 * _unsetenv - Remove an environment variable
 * @function_args: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(function_args *function_args, char *var)
{
	string_list *node = function_args->environment_list;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = sw(node->string, var);
		if (p && *p == '=')
		{
			function_args->environment_changed =
				dni(&(function_args->environment_list), i);
			i = 0;
			node = function_args->environment_list;
			continue;
		}
		node = node->next;
		i++;
	}
	return (function_args->environment_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @function_args: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(function_args *function_args, char *var, char *value)
{
	char *buf = NULL;
	string_list *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = function_args->environment_list;
	while (node)
	{
		p = sw(node->string, var);
		if (p && *p == '=')
		{
			free(node->string);
			node->string = buf;
			function_args->environment_changed = 1;
			return (0);
		}
		node = node->next;
	}
	ane(&(function_args->environment_list), buf, 0);
	free(buf);
	function_args->environment_changed = 1;
	return (0);
}

