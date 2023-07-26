#include "main.h"
/**
 * find_env - function that search for existing env variable
 * @var: variable
 * Return: index if found, -1 if not
 */
int find_env(const char *var)
{
	int i = 0;/*index*/
	int l;
	char *env_var;

	while ((env_var = environ[i]) != NULL)
	{
		l = _strcspn(env_var, "=");
		if (_strncmp(env_var, var, l) == 0 && var[l] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

/**
 * _getenv - function to get the value of an environment variable
 * @a: pointer to the name of env varable
 * Return: pointer to the value of environment vrible
 */
char *_getenv(const char *a)
{
	char **e, *v;

	for (e = environ; *e != NULL; e++)
	{
		/*check if current variable start with the specified name*/
		if (_strncmp(a, *e, _strlen(a)) == 0)
		{
			/*if match found*/
			v = *e + _strlen(a);
			return (*v == '=' ? v + 1 : v);
		}
	}
	return (NULL);
}

/**
 * p_env - a function that prints current environment
 */
void p_env(void)
{
	char **e; /* envirnment variabel*/

	for (e = environ; *e != NULL; e++)
	{
		write(STDOUT_FILENO, *e, strlen(*e)); /* print env variable*/
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * set_env - function that set an environment variabe
 * @var: the variable
 * @n: the guven value
 * Return: ON success 0
 */
int set_env(const char *var, const char *n)
{
	int i; /*index*/
	int num = 0; /*number of variables*/
	char *new_env;
	void *temp; /*temporrary environment*/

	i = find_env(var);

	if (i != 1)
	{
		new_env = malloc(_strlen(var) + _strlen(n) + 2);
		if (!new_env)
		{
			perror("Error");
			return (-1);
		}
		_strcpy(new_env, var);
		_strcat(new_env, "=");
		_strcat(new_env, n);

	free(environ[i]);
		environ[i] = new_env;
	}
	else
	{
		while (environ[num] != NULL)
			num++;
		temp = _realloc((void *)environ, (num + 2) * sizeof(char *),
				(num + 1) * sizeof(char *));
		if (!temp)
		{
			perror("Error");
			return (-1);
		}
		environ = (char **)temp;
		new_env = malloc(_strlen(var) + _strlen(n) + 2);
		if (!new_env)
		{
			perror("Error");
			return (-1);
		}
		_strcpy(new_env, var);
		_strcat(new_env, "=");
		_strcat(new_env, n);

		environ[num] = new_env;
		environ[num + 1] = NULL;
	}
	return (0);
}

/**
 * unset_env - function that unset an envir variable
 * @var: the variable to unset
 * Return: 0 on succes
 */
int unset_env(const char *var)
{
	int j, i;

	j = find_env(var);

	if (j != -1)
	{
		free(environ[j]);
		for (i = j; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
	}
	else
	{
		perror("Error");
		return (-1);
	}
	return (0);
}
