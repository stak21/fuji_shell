#include "fuji.h"

/**
 * linked_PATH - builds a linked list of the PATH directories
 *
 * Return: pointer to the linked list
 */
lp_t *linked_PATH(void)
{
	char *path;
	lp_t *head;
	int i, start;

	head = NULL;
	path = _getenv("PATH");
	i = start = 0;
	while (path[i] != '\0')
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			len = i - start;
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

int main(void);
{
	lp_t *list;

	list = linked_PATH();
	while (list->next != NULL)
	{
		printf("%s\n", list->dir)
		list = list->next;
	}
	return (0);
}	
			
