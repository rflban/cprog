#ifndef __SET_2_H
#define __SET_2_H

#include <stdbool.h>

#ifndef item_t
#undef  item_t
#endif
#define item_t int

typedef struct set_t* set_t;

int set_pop(set_t set, item_t *item);

int set_push(set_t set, item_t item);

bool set_is_full(const set_t set);

bool set_is_empty(const set_t set);

void set_clear(set_t set);

void set_destroy(set_t set);

set_t set_create(void);

struct node_t *set_is_containg(const set_t set, const item_t item);

#endif /*SET_2_H*/
