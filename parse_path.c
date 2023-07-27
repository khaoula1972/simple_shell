#include "main.h"
/**
 * parse_path - parse path envirnment into linked list
 */
void parse_path(void)
{
	char *path, *env_path, *token;
	DirNode *new_node;

	env_path = _getenv("PATH"); /* get the value of the path env var*/
	if (env_path == NULL)
	{
		/* if path not set */
		perror("Error");
		exit(EXIT_FAILURE);
	}

	path = _strdup(env_path); /* duplicate string to get tokenized*/
	if (path == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":"); /* tokenization */
	while (token != NULL)
	{/* allocate memroy for new directory*/
		new_node = (DirNode *)malloc(sizeof(DirNode));
		if (new_node == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		new_node->dir = _strdup(token); /* duplicate token for new node*/
		new_node->next = path_list;
		path_list = new_node;

		token = strtok(NULL, ":"); /*get next token */
	}

	free(path);
}

