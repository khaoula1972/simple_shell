#include "main.h"

/**
 * print_environment - prints the current environment
 * @args: Structure containing potential arguments. Used to maintain
 * Return: Always 0
 */
int print_environment(function_args *args)
{
	ps_ls(args->environment_list);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 * Return: the value
 */
char *_getenv(function_args *info, const char *name)
{
	string_list *node = info->environment_list;
	char *ptr;

	while (node)
	{
		ptr = sw(node->string, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env - Initialize a new environment variable,
 * @args: Structure containing potential arguments. Used to maintain
 *  Return: Always 0
 */
int set_env(function_args *args)
{
	if (args->arg_count != 3)
	{
		erputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(args, args->arg_vector[1], args->arg_vector[2]))
		return (0);
	return (1);
}

/**
 * unset_env - Remove an environment variable
 * @args: Structure containing potential arguments. Used to maintain
 *  Return: Always 0
 */
int unset_env(function_args *args)
{
	int i;

	if (args->arg_count == 1)
	{
		erputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= args->arg_count; i++)
		_unsetenv(args, args->arg_vector[i]);

	return (0);
}

/**
 * fill_env - populates env linked list
 * @args: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int fill_env(function_args *args)
{
	string_list *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		ane(&node, environ[i], 0);
	args->environment_list = node;
	return (0);
}
