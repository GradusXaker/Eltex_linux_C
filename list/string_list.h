#include "string.h"

typedef struct string_list list_t;
typedef struct string_list_node list_node_t;

struct string_list
{
	list_node_t *head;
};

struct string_list_node
{
	str_t *data;
	list_node_t *next;
};

str_t *list_find(list_t *list, str_t *search_for);

list_node_t *node__create(str_t *data, list_node_t *next);

list_t *list_create();

void list_free(list_t *list);

void list_add(list_t *list, str_t *data);

void list_remove_all(list_t *list, str_t *str);
