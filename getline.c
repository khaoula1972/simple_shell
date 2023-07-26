#include "main.h"

/**
 * _getline - reads from the standard input in chunks
 * of READ_BUF_SIZE and stores it in the buf variable
 * @ptr: input buffer
 * @line_len: buffer size
 * @fd: file descriptor
 * Return: num of chars read (including newline), -1 on error
 */

ssize_t _getline(char **ptr, size_t *line_len, int fd)
{
	/*  Static variables buff, i, and len to keep track*/
	/*  of the current state of the buffer */
	static char buff[READ_BUF_SIZE];
	static size_t i, len; /* current position in buffer and size*/
	size_t k = 0;
	ssize_t r = 0;/*number of read bytes*/
	char *p = NULL, *new_p; /*buffer*/
	int n; /*number of newline found*/

	p = *ptr;
	if (p && line_len)
		k = *line_len; /* store current ptr and line lenghth in local var*/

	while (1)
	{
		/*if buffer is empty or have all valide char from buffer*/
		if (i >= len)
		{
			r = read(fd, buff, READ_BUF_SIZE);/*read data*/
			if (r <= 0)
			{
				if (k == 0 && r == 0)
				{
					/* EOF */
					return (0);
				}
				return (-1);
			}
			i = 0;
			len = r;
		}
		/*allocate memory for buffer*/
		if (k >= *line_len)
		{
			*line_len += READ_BUF_SIZE;
			new_p = _realloc(p, k, *line_len + 1);
			if (!new_p)
			{
				/* failure case*/
				free(p);
				*ptr = NULL;
				return (-1);
			}
			p = new_p;
			*ptr = p;
		}
		p[k] = buff[i]; /* copy char from buff to user's*/
		if (p[k] == '\n')
		{
			n = 1;
			p[k + 1] = '\0'; /*null terminator*/
			i++;
			break;
		}
		k++;
		i++;
	}

	return (n);
}

