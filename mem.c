#include "main.h"
/**
 * read_buff - reads data from stdin into buff array with
 * max read size of READ_BUFF_SZIE
 * @buff: buffer array
 * @len: pointer to num of bytes read from the input
 * Return: num of bytes read
 */
ssize_t read_buff(char *buff, size_t *len)
{
	ssize_t rd = read(STDIN_FILENO, buff, READ_BUF_SIZE);

	if (rd > 0)
		*len = rd;
	return (rd);
}

/**
 * read_input - read input cmd from the user
 * Return: a pointer to the input
 */
char *read_input(void)
{
	char *input = NULL;
	size_t input_len = 0;
	
	if (_getline(&input, &input_len, STDIN_FILENO) == -1)
	{
		/* EOF */
		free(input);
		input = _strdup("");
	}

	return (input);
}

/**
 * _realloc - reallocates memory for a given pointer
 * @ptr: pointer to reallocate memory
 * @old_size: size of the memory block pointed to by ptr
 * @new_size: new desired size of the memory block
 * Return: new pointer to the reallocated memory block
 */
char *_realloc(char *ptr, size_t old_size, size_t new_size)
{
	char *new_ptr = malloc(new_size);

	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		_strncpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}
