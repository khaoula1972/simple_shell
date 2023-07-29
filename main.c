#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	function_args info[] = { FUNCTION_ARGS_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				erputs(av[0]);
				erputs(": 0: Can't open ");
				erputs(av[1]);
				erputchar('\n');
				erputchar(FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	info->read_file_descriptor = fd;
	}
	populate_env_list(info);
	prompt(info, av);
	return (EXIT_SUCCESS);
}

