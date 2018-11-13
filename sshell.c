#include "fuji.h"

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
	char *ptr = NULL;
	char **string = NULL;
	size_t size = 0;
	int len;
	int status;
	pid_t parent;

	while (1)
	{
		parent = fork();	
		if (!parent)
		{
			printf("Shell$: ");
			len = getline(&ptr, &size, stdin);
			if (len == -1)
			{
				dprintf(2, "Exiting\n");
				free(string);
				exit(-1);
			}
			ptr[len - 1] = '\0';
			string = strtow(ptr);

			if (execve(string[0], string, NULL) == -1)
				perror("Error\n");
		}
		else
			wait(&status);
	}
			printf("ending\n");	
	return (0);

}
