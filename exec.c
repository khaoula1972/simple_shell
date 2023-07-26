#include "main.h"
/**
 * search_and_execute - search for a cmd then execute it
 * @command: the command
 * @args: an array of arguments to be passed to the command
 */
void search_and_execute(const char *command, char **args)
{
	pid_t pid; /* new process */
	char *envp[] = {NULL}; /* empty environment varaible */
	char *full_path;
	DirNode *current; /* current node */

	/* check if cmd contains a slash or not */
	if (_strchr(command, '/') != NULL)
	{
		pid = fork(); /* fork a new process*/

		if (pid == 0)
		{
			/* child process */
			if (execve(command, args, envp) == -1)
			{
				write(STDERR_FILENO, command, _strlen(command));
				write(STDERR_FILENO, ": 1: ", 5);
				write(STDERR_FILENO, args[0], _strlen(args[0]));
				perror(": not found");
				exit(EXIT_FAILURE);
			}
		}
		wait(NULL); /* wait for child process */
	}
	else
	{
		/* means its not a full path */
		current = path_list; /* searching in the path list*/
		while (current != NULL)
		{
			/* let's get the full path first */
			full_path = get_full_path(current->dir, command);
			if (access(full_path, X_OK) == 0)
			{
				pid = fork();

				if (pid == 0)
				{
					if (execve(full_path, args, envp) == -1)
					{
						/* print error */
						write(STDERR_FILENO, full_path, _strlen(full_path));
						write(STDERR_FILENO, ": 1: ", 5);
						write(STDERR_FILENO, args[0], _strlen(args[0]));
						perror(": not found");
						free(full_path);
						exit(EXIT_FAILURE);
					}
					exit(EXIT_SUCCESS);
				}
				free(full_path);
				wait(NULL); /* wait for child process */
				return;
			}
			free(full_path);
			current = current->next; /* next directory */
		}

		/* command not found */
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		perror(": not found");
	}
}

