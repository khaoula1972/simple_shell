#include "main.h"

/**
 * print_environment - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int print_environment(function_args *info)
{
	ps_ls(info->environment_list);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(function_args *info, const char *name)
{
	string_list *node = info->environment_list;
	char *p;

	while (node)
	{
		p = sw(node->string, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(function_args *info)
{
	if (info->arg_count != 3)
	{
		erputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->arg_vector[1], info->arg_vector[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(function_args *info)
{
	int i;

	if (info->arg_count == 1)
	{
		erputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->arg_count; i++)
		_unsetenv(info, info->arg_vector[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(function_args *info)
{
	string_list *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ane(&node, environ[i], 0);
	info->environment_list = node;
	return (0);
}

