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

	if (argc < 2)
	{
		perror("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}

	int i = 1;
	while (av[i])
	{
		if (stat(av[i], &st) == 0)
			write(2, av[i], strlen(av[i]))
		i++;
	}

	return (0);
}
