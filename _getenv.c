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
	char *ret_ptr;

	i = j = 0;
	ret_ptr = NULL;
	while (environ[i] != NULL)
	{
		res = _strcmp(name, (const char *)environ[i]);
		if (res == 1)
		{
			len = _strlen(environ[i]);
			while (environ[i][j] != '=')
				j += 1;
			len -= j;
			ret_ptr = malloc(sizeof(char) * len + 1);
			return (ret_ptr = _memcpy(ret_ptr, environ[i] + (j + 1), len + 1));		
		}
		i++;
	}
	printf("Error\n");
	return (NULL);
}
