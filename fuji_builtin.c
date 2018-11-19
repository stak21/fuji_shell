#include "fuji.h"

/**
 * fuji_env - prints environmental variable
 * @args - array of arguments
 */
void fuji_env(char **args, char **env)
{
	int i, len;
	(void)args;

	i = 0;
	while (env[i] != NULL)
	{
		len = strlen(env[i]);
		write(2, env[i], len);
		write(2, "\n", 1);
		i++;
	}
}

/**
 * fuji_exit - exits the shells
 * @args - array of arguments
 */
void fuji_exit(char **args, char **env)
{
	(void)args;
	(void)env;

	exit(98);
}
/**
 * fuji_built - checks for built-in commands and execute them
 * @args - array of arguments
 */
void fuji_built(char **args, char **env)
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
			b_ins[i].f(args, env);
			break;
		}
	}
}
