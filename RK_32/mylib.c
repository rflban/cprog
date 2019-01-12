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
	if (str == NULL)
	{
		return;
	}

	struct list_head *it;
	struct list_head *temp;

	list_for_each_safe(it, temp, &str->str_head)
	{
		free(list_entry(it, chr_t, list));
	}

	free(str);
}

void str_insert(str_t *str, int pos, char c)
{
	if (str == NULL)
	{
		return;
	}

	if (str->len < pos)
	{
		return;
	}

	int i = 0;
	chr_t *chr;
	struct list_head *it;
	struct list_head *temp;
	
	chr = (chr_t*)malloc(sizeof(chr_t));

	if (chr == NULL)
	{
		return;
	}

	chr->chr = c;

	list_for_each_safe(it, temp, &str->str_head)
	{
		if (i == pos - 1)
		{
			break;
		}

		i++;
	}

	__list_add(&chr->list, it, it->next); 
}

void str_remove(str_t *str, int pos)
{
	if (str == NULL)
	{
		return;
	}

	if (str->len <= pos)
	{
		return;
	}

	int i = 0;
	chr_t *chr;
	struct list_head *it;
	struct list_head *temp;

	list_for_each_safe(it, temp, &str->str_head)
	{
		if (i == pos)
		{
			break;
		}

		i++;
	}

	chr = list_entry(it, chr_t, list);

	it->prev->next = it->next;
	it->next->prev = it->prev;

	free(chr);
}

