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
	(void)argv;

	while (1)
	{
		if (isatty(fileno(stdin)))
			write(2, "Fuji$ ", 6);
		signal(SIGINT, signal_handler);
		len = getline(&ptr, &size, stdin);
		if (len == EOF)
			free_cptrn(-1, 1, ptr);
		ptr[len - 1] = '\0';
		if (*ptr == '\0' || (*ptr == '.' && ptr[1] == '\0'))
			free_cptrn(0, 1, ptr);
		string = strtow(ptr);
		if (!string)
			free_cptrn(0, 1, ptr);
		fuji_built(string, env);
		parent = fork();
		if (parent == 0)
		{
			check_path(string);
			if (execve(string[0], string, NULL) == -1)
			{
				perror("./shell: ");
				free_array(string);
				free_cptrn(0, 1, ptr);
			}
		}
		else
			if (!wait(&status))
				break;
	}
	return (0);
}
