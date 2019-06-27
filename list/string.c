#include "string.h"

static void str__realloc(str_t *str, uint16_t new_cap)
{
	str->data = realloc(str->data, sizeof(*str->data) * new_cap);
	str->cap = new_cap;
}

str_t *new_str(uint16_t cap)
{
	str_t *str = malloc(sizeof(str_t));

	str->data = malloc(sizeof(*str->data) * cap);
	str->cap = cap;
	str->len = 0;

	return str;
}

void str_free(str_t *str)
{
	free(str->data);
	free(str);
}

uint16_t str__len(const char *str)
{
	uint16_t len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}

str_t *str_dup(const char *str)
{
	str_t *dup = new_str(str__len(str));

	dup->data = memcpy(dup->data, str, dup->cap * sizeof(*dup->data));
	dup->len = dup->cap;

	return dup;
}

bool str_equals(str_t *one, str_t *another)
{
	if (one->len != another->len)
		return false;

	uint16_t c = 0;
	for (;(c < one->len) && (one->data[c] == another->data[c]); c++)
		;

	return c == one->len;
}

void str_append(str_t *str, uint8_t data)
{
	if (str->cap == str->len)
		str__realloc(str, str->cap + (str->cap / 2) + 1);

	str->data[str->len++] = data;
}

str_t *str_read()
{
	str_t *str = new_str(4);
	uint8_t ch;

	while (((ch = getchar()) != EOF) && (ch != '\n'))
		str_append(str, ch);

	return str;
}
