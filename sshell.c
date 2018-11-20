#include "fuji.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: list of arguments
 * @env: list of env vars
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char **env)
{
	char *ptr = NULL;
	char **string = NULL;
	size_t size = 0;
	int len, status;
	pid_t parent;
	(void)argc;

	while (1)
	{
		ptr = NULL;
		size = 0;
		if (isatty(fileno(stdin)))
			write(STDOUT_FILENO, "Fuji$ ", 6);
		signal(SIGINT, signal_handler);
		len = getline(&ptr, &size, stdin);
		if (len == EOF)
			free_cptrn(-1, 1, ptr);
		ptr[len - 1] = '\0';
		if (*ptr == '\0' || (*ptr == '.' && ptr[1] == '\0'))
		{
			free_cptrn(99, 1, ptr);
			continue;
		}
		string = strtow(ptr);
		if (!string)
		{
			free_cptrn(99, 1, ptr);
			continue;
		}
		free_cptrn(99, 1, ptr);
		if (fuji_built(string, env))
			continue;
		parent = fork();
		if (parent == 0)
		{
			check_path(string, env);
			if (execve(string[0], string, NULL) == -1)
			{
				perror(*argv);
				free_array(string);
				exit(0);
			}
		}
		else
		{
			free_array(string);
			if (!wait(&status))
				break;
		}
	}
	return (0);
}
