#include "fuji.h"

/**
* main - Entry point
* Return: Always 0 (Success)
*/

int main(int argc, char **argv)
{
	char *ptr = NULL;
	char **string = NULL;
	size_t size = 0;
	int len;
	int status;
	pid_t parent;
	int non_interactive;

	non_interactive = 0;

	/** inline */
	if (argc > 1)
	{
		if (execve(argv[1], argv + 1, NULL) == -1)
		{
			perror("./shell");
			exit(0);
		}
	}

	while (!non_interactive)
	{
	write(2, "Fuji$ ", 6);
	if((len = getline(&ptr, &size, stdin)) == -1)
		non_interactive = 1;
		ptr[len - 1] = '\0';
		parent = fork();	
		if (parent == 0)
		{
			if (*ptr == '\0')
			{
				free(ptr);
				exit(0);
			}
			string = strtow(ptr);
			check_path(string);
			if (execve(string[0], string, NULL) == -1)
			{
				perror("./shell");
				exit(0);
			}
		}
		else
		{
			wait(&status);
			free(ptr);
			ptr = NULL;
			if (status != 0 || non_interactive)
				break;
		}
	}

			printf("ending\n");	
	return (0);

}
