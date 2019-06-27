#include "string_list.h"

str_t *list_find(list_t *list, str_t *search_for)
{
	list_node_t *node = list->head;

	while (node) {
		list_node_t *next = node->next;

		if (str_equals(node->data, search_for))
			return node->data;

		node = next;
	}

	return NULL;
}

list_node_t *node__create(str_t *data, list_node_t *next)
{
	list_node_t *node = malloc(sizeof(list_node_t));

	node->data = data;
	node->next = next;

	return node;
}

list_t *list_create()
{
	list_t *list = malloc(sizeof(list_t));

	list->head = NULL;

	return list;
}

void list_free(list_t *list)
{
	list_node_t *node = list->head;

	while (node) {
		list_node_t *next = node->next;
		free(node);
		node = next;
	}
}

void list_add(list_t *list, str_t *data)
{
	list_node_t *new_node = node__create(data, NULL);

	if (!list->head) {
		list->head = new_node;
		return;
	}

	list_node_t *node = list->head;

	while (node->next)
		node = node->next;

	node->next = new_node;
}

/* list_remove_all: remove all occurences of str in list. */
void list_remove_all(list_t *list, str_t *str)
{
	list_node_t **node = &list->head;

	while (*node) {
		if (str_equals((*node)->data, str)) {
			list_node_t *found = *node;
			*node = (*node)->next;
			free(found);
		} else {
			node = &(*node)->next;
		}
	}
}
