#include "main.h"
/**
 * get_full_path - concatenate a directory with command
 * @dir: the durectory
 * @cmd: the command
 * Return: the full path of the command
 */
char *get_full_path(const char *dir, const char *cmd)
{
	size_t len1 = _strlen(dir); /* length of directory */
	size_t len2 = _strlen(cmd); /* length of command*/
	char *full_path = malloc(len1 + len2 + 2); /* allocate memory for path */

	if (full_path == NULL)
	{
		/* error case of allocation */
		perror("Error");
		exit(EXIT_FAILURE);
	}

	/* copy the directory path to the full path string */
	_strcpy(full_path, dir);
	full_path[len1] = '/'; /* add slash to seperate directorry and cmd*/

	/*copy command to the full path after the slash*/
	_strcpy(&full_path[len1 + 1], cmd);

	return (full_path);
}

