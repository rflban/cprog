#ifndef __MYLIB_H
#define __MYLIB_H

#include "list.h"

typedef struct str_t
{
	int len;
	struct list_head str_head;
}
str_t;

typedef struct chr_t
{
	char chr;

	struct list_head list;
}
chr_t;

str_t *str_create();

int str_search(str_t *str, char *srch);

void str_delete(str_t *str);
void str_insert(str_t *str, int pos);
void str_remove(str_t *str, int pos);

#endif

