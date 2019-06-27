#include <stdio.h>
#include "string_list.h"

int main(void)
{
	list_t *list = list_create();

	printf("Привет) Сначала необходимо чем-то наполнить список...\n\n");
	for (uint8_t c = 0; c < 5; c++) {
		printf("Добавить в список: ");
		list_add(list, str_read());
	}

	printf("Отлично!\nТеперь введите то, что нужно найти: ");
	str_t *searchfor = str_read();

	str_t *found = list_find(list, searchfor);
	if (found)
		printf("Строка найдена! %s\n", found->data);
	else
		printf("Строка не найдна :c\n");

	return 0;
}
