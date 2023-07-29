#include "main.h"

/**
 * exit_shell - exits the shell
 * @function_args: structure containing potential arguments
 * used to maintain constant function prototype.
 *
 * Return: exits with a given exit status
 *         (0) if function_args->arg_vector[0] != "exit"
 */

int exit_shell(function_args *function_args)
{
	int exitcheck;

	if (function_args->arg_vector[1])  /* If there is an exit argument */
	{
		exitcheck = _erratoi(function_args->arg_vector[1]);
		if (exitcheck == -1)
		{
			function_args->return_status = 2;
			perr(function_args, "Illegal number: ");
			erputs(function_args->arg_vector[1]);
			erputchar('\n');
			return (1);
		}
		function_args->line_error_count = _erratoi(function_args->arg_vector[1]);
		return (-2);
	}
	function_args->line_error_count = -1;
	return (-2);
}

/**
 * change_directory - changes the current directory of the
 * process
 * @function_args: Structure containing potential arguments;
 * used to maintain constant function prototype.
 *
 * Return: Always 0
 */
int change_directory(function_args *function_args)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!function_args->arg_vector[1])
	{
		dir = _getenv(function_args, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(function_args, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(function_args->arg_vector[1], "-") == 0)
	{
		if (!_getenv(function_args, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(function_args, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(function_args, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(function_args->arg_vector[1]);
	if (chdir_ret == -1)
	{
		perr(function_args, "can't cd to ");
		erputs(function_args->arg_vector[1]), erputchar('\n');
	}
	else
	{
		_setenv(function_args, "OLDPWD", _getenv(function_args, "PWD="));
		_setenv(function_args, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * shelp - changes the current directory of the process
 * @function_args: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int shelp(function_args *function_args)
{
	char **arg_array;

	arg_array = function_args->arg_vector;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

