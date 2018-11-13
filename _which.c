#include "fuji.h"

/**
 * main - status of a file
 * @argc - argument count
 * @argv - arguments
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	struct stat st;
	int i = 1;
	int len;

	if (argc < 2)
	{
		/* change later */
		write(2, "error\n", 7);
		return (1);
	}

	while (argv[i])
	{
		if (stat(argv[i], &st) == 0)
		{
			len = strlen(argv[i]);
			argv[i][len] = '\n';
			write(2, argv[i], len + 1);
		}
		i++;
	}

	return (0);
}
