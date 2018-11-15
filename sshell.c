#include "fuji.h"

/**
* main - Entry point
* Return: Always 0 (Success)
*/

int main(int argc, char **argv)
{
	int ind = 0;
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

	while (1)
	{
			if (isatty(fileno(stdin)))
				write(2, "Fuji$ ", 6);
			if((len = getline(&ptr, &size, stdin)) == EOF)
			{
				free(ptr);
				exit(-1);
			}
			ptr[len - 1] = '\0';
			printf("hillo\n");
			parent = fork();	
			if (parent == 0)
			{
				if (*ptr == '\0' || (*ptr == '.' && ptr[1] =='\0'))
				{
					free(ptr);
					exit(0);
				}
				if (!(string = strtow(ptr)))
				{
					free(ptr);
					exit(0);
				}
				check_path(string);
				if (string == NULL)
					perror("Error: string is NULL\n");
				if (execve(string[0], string, NULL) == -1)
				{
					perror("./shell");
					while (string[ind])
					{
						free(string[ind]);
						ind += 1;
					}
					free(string);			
					free(ptr);
					exit(0);
				}
			}
			else
			{
				wait(&status);
				if (status != 0 || non_interactive)
					break;
			}
	}

			printf("ending\n");	
	return (0);

}
