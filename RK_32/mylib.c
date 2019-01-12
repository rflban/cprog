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
	str->len += 1;
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
	str->len -= 1;
}

int str_search(str_t *str, char *srch)
{
	if (str == NULL || srch == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = 0;
	int ind;
	int same = 0;
	int finded = 0;
	int srch_len;
	chr_t *chr;
	struct list_head *it;
	struct list_head *temp;

	for (srch_len = 0; srch[srch_len] != '\0'; srch_len++);

	if (srch_len == 0)
	{
		return 0;
	}

	list_for_each_safe(it, temp, &str->str_head)
	{
		chr = list_entry(it, chr_t, list);

		if (same)
		{
			if (chr->chr == srch[j])
			{
				j++;
			}
			else
			{
				j = 0;
				same = 0;
			}
		}
		else
		{
			if (chr->chr == srch[j])
			{
				j++;
				same = 1;
			}
		}

		if (j >= srch_len)
		{
			finded = 1;
			ind = i - j + 1;

			break;
		}

		i++;
	}
	
	if (!finded)
	{
		return -1;
	}

	return ind;
}

