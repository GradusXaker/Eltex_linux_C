#ifndef _STDIO_H
	#include <stdio.h>
#endif
#ifndef _STDLIB_H
	#include <stdlib.h>
#endif
#ifndef _STRING_H
	#include <string.h>
#endif
#ifndef _STDINT_H
	#include <stdint.h>
#endif
#ifndef _STDBOOL_H
	#include <stdbool.h>
#endif

#define _NSTRING_H 1

typedef struct string
{
	uint8_t *data;
	uint16_t cap;
	uint16_t len;
} str_t;

str_t *new_str(uint16_t cap);
void str_free(str_t *str);
uint16_t str__len(const char *str);
str_t *str_dup(const char *str);
bool str_equals(str_t *one, str_t *another);
str_t *str_read();
void str_append(str_t *str, uint8_t data);
