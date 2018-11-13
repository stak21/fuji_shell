#include "fuji.h"

/**
 * linked_PATH - builds a linked list of the PATH directories
 *
 * Return: pointer to the linked list
 */
lp_t *linked_PATH(void)
{
	char *path;
	int len;
	lp_t *head;
	char *str1;
	int i, start;

	head = NULL;
	path = _getenv("PATH");
	i = start = 0;
	while (path[i] != '\0')
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			len = i - start;
			if (path[i + 1] == '\0')
				len += 1;
			str1 = malloc(sizeof(char) * len + 1);
			str1 = _memcpy(str1, path + start, len);
			str1[len + 1] = '\0';
			start = i + 1;
			add_node_end(&head, str1);
		}
		i++;
	}
	return (head);
}
