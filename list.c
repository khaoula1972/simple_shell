#include "main.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
string_list *add_node(string_list **head, const char *str, int num)
{
	string_list *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(string_list));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(string_list));
	new_head->number = num;
	if (str)
	{
		new_head->string = _strdup(str);
		if (!new_head->string)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
string_list *ane(string_list **head, const char *str, int num)
{
	string_list *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(string_list));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(string_list));
	new_node->number = num;
	if (str)
	{
		new_node->string = _strdup(str);
		if (!new_node->string)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * ps_ls - prints only the str element of a string_list linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t ps_ls(const string_list *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->string ? h->string : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * dni - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int dni(string_list **head, unsigned int index)
{
	string_list *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->string);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->string);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a string_list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(string_list **head_ptr)
{
	string_list *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->string);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

