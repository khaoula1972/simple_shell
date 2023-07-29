#include "main.h"

/**
 * clear_function_args - initializes function_args struct
 * @function_args: struct address
 */
void clear_function_args(function_args *function_args)
{
	function_args->arg_string = NULL;
	function_args->arg_vector = NULL;
	function_args->command_path = NULL;
	function_args->arg_count = 0;
	function_args->line_error_count = 0;
}

/**
 * set_function_args - initializes function_args struct
 * @function_args: struct address
 * @av: argument vector
 */
void set_function_args(function_args *function_args, char **av)
{
	int i = 0;

	function_args->program_filename = av[0];
	if (function_args->arg_string)
	{
		function_args->arg_vector = strtk(function_args->arg_string, " \t");
		if (!function_args->arg_vector)
		{

			function_args->arg_vector = malloc(sizeof(char *) * 2);
			if (function_args->arg_vector)
			{
				function_args->arg_vector[0] = _strdup(function_args->arg_string);
				function_args->arg_vector[1] = NULL;
			}
		}
		for (i = 0; function_args->arg_vector && function_args->arg_vector[i]; i++)
			;
		function_args->arg_count = i;

		replace_alias(function_args);
		replace_vars(function_args);
	}
}

/**
 * free_function_args - frees function_args struct fields
 * @function_args: struct address
 * @all: true if freeing all fields
 */
void free_function_args(function_args *function_args, int all)
{
	ffree(function_args->arg_vector);
	function_args->arg_vector = NULL;
	function_args->command_path = NULL;
	if (all)
	{
		if (!function_args->command_buffer)
			free(function_args->arg_string);
		if (function_args->environment_list)
			free_list(&(function_args->environment_list));
		if (function_args->alias_node)
			free_list(&(function_args->alias_node));
		ffree(function_args->modified_environment);
		function_args->modified_environment = NULL;
		bfree((void **)function_args->command_buffer);
		if (function_args->read_file_descriptor > 2)
			close(function_args->read_file_descriptor);
		_putchar(FLUSH);
	}
}

