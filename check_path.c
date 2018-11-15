#include "fuji.h"

/**
 * check_path - check if command is in the path directories
 *
 * Return: pointer to the linked list
 */
void check_path(char **string)
{
	char *str1, *str2, *path;
	int i, start, last;

	if (!string)
	{
		perror("Error: string is NULL\n");
		exit(-1);
	}
	str1 = str_concat("/", string[0]);
	if (str1 == NULL)
	{
		perror("Error: str is NULL\n");
		exit(-1);
	}
	path = _getenv("PATH");
	if (path == NULL)
	{
		free(str1);
		perror("Error: path is NULL\n");
	}

	start = i = last = 0;
	
	while (path[i])
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			if (path[i + 1] == '\0')
			{
				i += 1;
				last = 1;
			}
			else
				path[i] = '\0';
			str2 = str_concat(path + start, str1);
			if (str2 == NULL)
			{
				perror("Error: str is NULL\n");
				exit(-1);
			}
			if (access(str2, F_OK) == 0)
			{
				string[0] = str2;
				free(str1);
				return;
			}
			free(str2);
			if (last)
				break;
			path[i] = ':';
			start = i + 1;
		}
			i += 1;
	}
	free(str1);
}
