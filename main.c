#include "main.h"

DirNode *path_list = NULL;

/**
 * main - This is our shell
 * Return: on success always return 0
 */
int main(void)
{
	int i = 0;/*status*/
	char *input, **args;

	parse_path();

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4); /* the prompt*/
		fflush(stdout); /* flush th eoutput buffer to ensure prompt is displayed*/
		input = read_input(); /* read users input*/

		if (input == NULL)
			break;
		
		args = parse_input(input); /*parse input to args*/

		if (args[0] != NULL)
		{
			/* if cmd was provided*/
			/*handle nuiltin commands without forking new proces*/
			if (_strcmp(args[0], "cd") == 0)
			{
				if (args[1] != NULL)
				{
					/*if dircetory was provided*/
					if (chdir(args[1]) != 0)
						perror("Error");
				}
			}
			else if (_strcmp(args[0], "exit") == 0)
			{
				/* convert to integer */
				if (args[1] != NULL)
					i = _atoi(args[1]);

				free(input);
				free(args);
				exit(i);
			}
			else if (_strcmp(args[0], "env") == 0)
			{
				p_env();
			}
			else if (_strcmp(args[0], "setenv") == 0)
			{
				/* if both var and vaklue are given*/
				if (args[1] != NULL && args[2] != NULL)
				{
					if (set_env(args[1], args[2]) == -1)
						perror("Error");
				}
				else
					perror("Error: setenv syntax: setenv VARIABLE VALUE");
			}
			else if (_strcmp(args[0], "unsetenv") == 0)
			{
				/* var should be provided*/
				if (args[1] != NULL)
				{
					if (unset_env(args[1]) == -1)
						perror("Error");
				}
				else
					perror("Error: unsetenv syntax: unsetenv VARIABLE");
			}
			else
			{
				search_and_execute(args[0], args);
			}
		}
		free(input);
		free(args);
	}

	free_path_list();

	return (0);
}

/**
 * free_path_list - free the linked list of directories
 */
void free_path_list(void)
{
	DirNode *current = path_list;
	DirNode *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->dir);
		free(temp);
	}
	path_list = NULL;
}

