#include "fuji.h"

/**
* ls_path - lists the directories in the PATH env
* 
*/

void ls_path(void)
{
	char *path;
	int i;

	i = 0;
	path = _getenv("PATH");
	while (path[i])
	{
		if (path[i] == ':')
			path[i] = '\n';
		i += 1;
	}
	write (2, path, _strlen(path));
	free(path);
}

