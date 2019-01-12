#include "mylib.h"

#include <stdlib.h>

str_t *str_create()
{
	str_t *new_str;

	new_str = (str_t*)malloc(sizeof(str_t));

	if (new_str == NULL)
	{
		return NULL;
	}

	new_str->len = 0;

	INIT_LIST_HEAD(&new_str->str_head);

	return new_str;
}

void str_delete(str_t *str)
{
	struct list_head *it;
	struct list_head *temp;

	list_for_each_safe(it, temp, &str->str_head)
	{
		free(list_entry(it, chr_t, list));
	}

	free(str);
}

