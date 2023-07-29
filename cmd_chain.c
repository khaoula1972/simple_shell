#include "main.h"

/**
 * chk_chain - checks we should continue chaining based on last status
 * @function_args: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */

void chk_chain(function_args *function_args, char *buf,
		size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (function_args->command_buffer_type == AND)
	{
		if (function_args->return_status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (function_args->command_buffer_type == OR)
	{
		if (!function_args->return_status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * is_chain_del - test if current char in buffer is a chain delimeter
 * @function_args: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int is_chain_del(function_args *function_args, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		function_args->command_buffer_type = OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		function_args->command_buffer_type = AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		function_args->command_buffer_type = CHAINING;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * replace_strs - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_strs(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @function_args: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_vars(function_args *function_args)
{
	int i = 0;
	string_list *node;

	for (i = 0; function_args->arg_vector[i]; i++)
	{
		if (function_args->arg_vector[i][0] != '$' ||
				!function_args->arg_vector[i][1])
			continue;

		if (!_strcmp(function_args->arg_vector[i], "$?"))
		{
			replace_strs(&(function_args->arg_vector[i]),
					_strdup(convert_number(function_args->return_status, 10, 0)));
			continue;
		}
		if (!_strcmp(function_args->arg_vector[i], "$$"))
		{
			replace_strs(&(function_args->arg_vector[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = nsw(function_args->environment_list,
				&function_args->arg_vector[i][1], '=');
		if (node)
		{
			replace_strs(&(function_args->arg_vector[i]),
					_strdup(_strchr(node->string, '=') + 1));
			continue;
		}
		replace_strs(&function_args->arg_vector[i], _strdup(""));
	}
	return (0);
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @function_args: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */

int replace_alias(function_args *function_args)
{
	int i;
	string_list *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = nsw(function_args->alias_node,
			function_args->arg_vector[0], '=');
		if (!node)
			return (0);
		free(function_args->arg_vector[0]);
		p = _strchr(node->string, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		function_args->arg_vector[0] = p;
	}
	return (1);
}
