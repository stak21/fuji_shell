#include "fuji.h"
extern char **environ;

/**
 * _getenv - get an environmental variable
 * @name: name of environ var
 * Return: pointer to env var
 */
char *_getenv(const char *name)
{
	int i, j;
	int res, len;

	i = j = 0;
	while (environ[i] != NULL)
	{
		res = _strcmp(name, (const char *)environ[i]);
		if (res == 1)
		{
			len = _strlen(environ[i]);
			while (environ[i][j] != '=')
				j += 1;
			len -= j;
			return (environ[i] + j + 1);
		}
		i++;
	}
	printf("Error\n");
	return (NULL);
}
