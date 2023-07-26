#include "main.h"
/**
 * parse_input - Parses the input string into args
 * @input: user's input
 * Return: array of pointer to parse args
 */
char **parse_input(char *input)
{
	char *token; /*var to store tokens*/
	char **args; /*array of args*/
	int count = 0;
	char *del = " \t\r\n\v\f"; /*delimeters to tokenize*/

	args = malloc(MAX_INPUT_LEN * sizeof(char *)); /* alloate memory for args*/

	if (!args)
	{
		/* allocation failure */
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, del); /*get first token*/

	while (token != NULL)
	{
		args[count] = token; /* store token in array */
		count++;
		token = strtok(NULL, del); /* get next token from inpt*/
	}

	args[count] = NULL;
	return (args);
}
