#include "fuji.h"
extern char **environ;

/**
 * fuji_env - prints environmental variable
 * @args - array of arguments
 */
void fuji_env(char **args)
{
	int i, len;
	(void)args;

	i = 0;
	while (environ[i] != NULL)
	{
		len = strlen(environ[i]);
		write(2, environ[i], len);
		write(2, "\n", 1);
		i++;
	}
}

/**
 * fuji_exit - exits the shells
 * @args - array of arguments
 */
void fuji_exit(char **args)
{
	(void)args;

	exit (98);
}
/**
 * setenv - initialize a  new environment variable, or modify one
 * @args - array of aguments
 *
void fuji_setenv(char **args)
{
	extern char **environ;
	char *var;
	int i;

	if (args == NULL)
		return;
	var = str_concat(arg[1], arg[2]);
	i = 0;
	while (environ[i] != NULL)
	{
		if (_strcmp(var, environ[i]) == 1)
			env[i] = var;
		i++;
	}
		
		len = strlen(environ[i]);
		write(2, environ[i], len);
		write(2, "\n", 1);
}*/
/**
 * fuji_built - checks for built-in commands and execute them
 * @args - array of arguments
 */
void fuji_built(char **args)
{
	built_t b_ins[] = {
		{"env", fuji_env},
		{"exit", fuji_exit},
		{NULL, NULL}
	};
	int i;

	if (args[0] == NULL)
		return;
	for (i = 0; i < 2; i++)
	{
		if (_strcmp2(args[0], b_ins[i].cmd) == 0)
		{
			b_ins[i].f(args);
			break;
		}
	}
}
