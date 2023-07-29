#include "main.h"

/**
 * prompt - main shell loop
 * @function_args: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */

int prompt(function_args *function_args, char **av)
{
	ssize_t r = 0;
	int builtin_return = 0;

	while (r != -1 && builtin_return != -2)
	{
		clear_function_args(function_args);
		if (is_inter(function_args))
			_puts("($) ");
		erputchar(FLUSH);
		r = get_input(function_args);
		if (r != -1)
		{
			set_function_args(function_args, av);
			builtin_return = find_builtin(function_args);
			if (builtin_return == -1)
				_find(function_args);
		}
		else if (is_inter(function_args))
			_putchar('\n');
		free_function_args(function_args, 0);
	}
	free_function_args(function_args, 1);
	if (!is_inter(function_args) && function_args->return_status)
		exit(function_args->return_status);
	if (builtin_return == -2)
	{
		if (function_args->exit_error_code == -1)
			exit(function_args->return_status);
		exit(function_args->exit_error_code);
	}
	return (builtin_return);
}

/**
 * find_builtin - finds a builtin command
 * @function_args: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 * 0 if builtin executed successfully,
 * 1 if builtin found but not successful,
 * -2 if builtin signals exit()
 */

int find_builtin(function_args *function_args)
{
	int i, built_in_return = -1;
	BuiltinCommandTable builtintbl[] = {
	{"exit", exit_shell},
	{"env", print_environment},
	{"help", shelp},
	{"setenv", set_env},
	{"unsetenv", unset_env},
	{"cd", change_directory},
	{"alias", _alias},
	{NULL, NULL}
	};

	for (i = 0; builtintbl[i].command_type; i++)
		if (_strcmp(function_args->arg_vector[0], builtintbl[i].command_type) == 0)
		{
			function_args->line_error_count++;
			built_in_return = builtintbl[i].command_function(function_args);
			break;
		}
	return (built_in_return);
}

/**
 * _find - finds a command in PATH
 * @function_args: the parameter & return info struct
 *
 * Return: void
 */

void _find(function_args *function_args)
{
	char *path = NULL;
	int i, k;

	function_args->command_path = function_args->arg_vector[0];
	if (function_args->line_count_flag == 1)
	{
		function_args->line_error_count++;
		function_args->line_count_flag = 0;
	}
	for (i = 0, k = 0; function_args->arg_string[i]; i++)
		if (!is_del(function_args->arg_string[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(function_args, _getenv(function_args, "PATH="),
			function_args->arg_vector[0]);
	if (path)
	{
		function_args->command_path = path;
		_fork(function_args);
	}
	else
	{
		if ((is_inter(function_args) || _getenv(function_args, "PATH=") ||
					function_args->arg_vector[0][0] == '/') && is_cmd(function_args,
						function_args->arg_vector[0]))
		_fork(function_args);
		else if (*(function_args->arg_string) != '\n')
		{
			function_args->return_status = 127;
			perr(function_args, "not found\n");
		}
	}
}

/**
 * _fork - forks a an exec thread to run cmd
 * @function_args: the parameter & return info struct
 *
 * Return: void
 */

void _fork(function_args *function_args)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(function_args->command_path, function_args->arg_vector,
					get_environ(function_args)) == -1)
		{
			free_function_args(function_args, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(function_args->return_status));
		if (WIFEXITED(function_args->return_status))
		{
			function_args->return_status = WEXITSTATUS(function_args->return_status);
			if (function_args->return_status == 126)
				perr(function_args, "Permission denied\n");
		}
	}
}

