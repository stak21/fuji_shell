#include "fuji.h"

/**
 * check_path - check if command is in the path directories
 *
 * Return: pointer to the linked list
 */
void check_path(char **string)
{
	lp_t *head, *tmp;
	char *str1, *str2;

	head = linked_PATH();
	tmp = head;
	str1 = str_concat("/", string[0]);
	while (tmp != NULL)
	{
		str2 = str_concat(tmp->dir, str1);
		if (access(str2, F_OK) == 0)
		{
			string[0] = str2;
			free_lp(str1, head);
			return;
		}
		free(str2);
		tmp = tmp->next;
	}
	free_lp(str1, head);
}
/**
 * free_lp - free allocated strings and list lip_t
 */
void free_lp(char *str1, lp_t *head)
{
	lp_t *tmp;

	free(str1);
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
