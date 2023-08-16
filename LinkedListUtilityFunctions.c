#include "shell.h"

/**
 * list_len - Linked List Operations: Utility Functions
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
size_t i = 0;
while (h)
{
h = h->next;
i++;
}
return (i);
}
/**
 * get_node_index - Gets the index of a node in the linked list.
 * @head: pointer to list headdd
 * @node: pointer to the nodeee
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
/**
 * node_starts_with - Finds a node whose string starts with a prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: The next character after the prefix to match.
 *
 * Return: Matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
 * print_list - prints all elements 
 * @h: pointer to first nodee
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
