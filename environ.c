#include "main.h"
/**
 * _getenv - function that can get env var value
 * @args: arguments conatined in structure
 * @var: env var name
 * Return: always Null
 */
char *_getenv(function_args *args, const char *var)
{
	string_list *n = args->environment_list;
	char *c;

	while (n)
	{
		c = sw(n->string, var);
		if (c && *c)
			return (c);
		n = n->next;
	}
	return (NULL);
}

/**
 * print_environment - function that prints curren env
 * @args: arguments contained in structure
 * Return: always 0
 */
int print_environment(function_args *args)
{
	ps_ls(args->environment_list);
	return (0);
}

/**
 * fill_env - function that fills the linked list
 * @args: arguments
 * Return: always 0
 */
int fill_env(function_args *args)
{
	string_list *env = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		ane(&env, environ[k], 0);
	args->environment_list = env;

	return (0);
}

/**
 * unset_env - function to delete env var
 * @args: arguments
 * Return: 0 on succes 1 on error
 */
int unset_env(function_args *args)
{
	int k;

	if (args->arg_count == 1)
	{
		erputs("Too few arguments.\n");
		return (1);
	}
	for (k = 1; k < args->arg_count; k++)
		_unsetenv(args, args->arg_vector[k]);

	return (0);
}

/**
 * set_env - function to set a new envir variable
 * @args: argments
 * Return: 0 on succes 1 on error
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
