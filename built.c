#include "main.h"
/**
 * exit_shell - function to exit shell with a specified status code
 * @args: a structure containing potential arguments
 * Return: 1 if error exit with status code if not
 */
int exit_shell(function_args *args)
{

	int exit_status;

	if (args->arg_vector[1])
	{
		exit_status = _atoi(args->arg_vector[1]);
		if (exit_status == -1)
		{
			args->return_status = 2;
			perr(args, "Illegal number: ");
			erputs(args->arg_vector[1]);
			erputchar('\n');
			return (1);
		}
		args->exit_error_code = _atoi(args->arg_vector[1]);
		return (-2);
	}
	args->exit_error_code = -1;
	return (-2);
}

/**
 * shelp -  a function that provides info
 * @a: structure contains args
 * Return: always 0
 */
int shelp(function_args *a)
{
	char **l;

	l = a->arg_vector;
	_puts("Help command called. Function not yet implemented. \n");
	if (0)
		_puts(*l);
	return (0);
}

/**
 * change_directory - a function that change the current direc
 * @args: structure with args
 * Return: always 0
 */
int change_directory(function_args *args)
{
	char *current_dir, *new_dir, buffer[1024];
	int result;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!args->arg_vector[1])
	{
		new_dir = _getenv(args, "HOME=");
		if (!new_dir)
			result = /* TODO:*/
				chdir((new_dir = _getenv(args, "PWD=")) ? new_dir : "/");
	}
	else
		result = chdir(args->arg_vector[1]);
	if (result == -1)
	{
		perr(args, "can't cd to ");
		erputs(args->arg_vector[1]);
		erputchar('\n');
	}
	else
	{
		_setenv(args, "OLDPWD", _getenv(args, "PWD="));
		_setenv(args, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
