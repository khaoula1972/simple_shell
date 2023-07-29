#include "main.h"
/**
 * free_list - frees all the nodes
 * @head_node: address of pointer to the head node
 * Return: nothing
 */
void free_list(string_list **head_node)
{
	string_list *next_node, *head, *node;

	if (!head_node || !*head_node)
		return;
	head = *head_node;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->string);
		free(node);
		node = next_node;
	}
	*head_node = NULL;
}

/**
 * dni - deletes the node at the given index
 * @list_head: address of pointer to the first node
 * @index: index of the node to delete
 * Return: 1 on success, 0 on failure
 */
int dni(string_list **list_head, unsigned int index)
{
	unsigned int count = 0;
	string_list *node, *prev_node;

	if (!list_head || !*list_head)
		return (0);
	if (!index)
	{
		node = *list_head;
		*list_head = (*list_head)->next;
		free(node->string);
		free(node);
		return (1);
	}
	node = *list_head;
	while (node)
	{
		if (count == index)
		{
			prev_node->next = node->next;
			free(node->string);
			free(node);
			return (1);
		}
		count++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * ane - appends a node at the end of the linked list
 * @list_head: address of pointer to the head node
 * @index_val: value for the 'num' field of the new node
 * @str_val: value for the 'str' field of the new node
 * Return: address of the new node
 */
string_list *ane(string_list **list_head, const char *str_val, int index_val)
{
	string_list *node, *new_node;

	if (!list_head)
		return (NULL);
	node = *list_head;
	new_node = malloc(sizeof(string_list));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(string_list));
	new_node->number = index_val;
	if (str_val)
	{
		new_node->string = _strdup(str_val);
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
		*list_head = new_node;
	return (new_node);
}

/**
 * ps_ls - prints only the 'str' element of a linked list
 * @first_node: pointer to the first node
 * Return: number of nodes in the list
 */
size_t ps_ls(const string_list *first_node)
{
	size_t count = 0;

	while (first_node)
	{
		_puts(first_node->string ? first_node->string : "(nil)");
		_puts("\n");
		first_node = first_node->next;
		count++;
	}
	return (count);
}

/**
 * add_node - inserts a node at the beginning of the linked list
 * @list_head: address of pointer to the head node
 * @str_val: value for the 'str' field of the new node
 * @index_val: value for the 'num' field of the new node
 * Return: address of the new node
 */
string_list *add_node(string_list **list_head,
		const char *str_val, int index_val)
{
	string_list *new_node;

	if (!list_head)
		return (NULL);
	new_node = malloc(sizeof(string_list));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(string_list));
	new_node->number = index_val;
	if (str_val)
	{
		new_node->string = _strdup(str_val);
		if (!new_node->string)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = *list_head;
	*list_head = new_node;
	return (new_node);
}
