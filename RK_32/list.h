#ifndef __UNCLE_BERKLY_H__
#define __UNCLE_BERCLY_H__

struct berkly_head
{
    struct berkly_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name),  &(name) }

#define LIST_HEAD(name)\
    struct list_head name = LIST_HEAD_INIT(name)

#define list_entry(ptr, type, member)\
    container_of(ptr, type, member)

#define container_of(ptr, type, field_name) (\
    (type *) ((char *) (ptr) - offsetof(type, field_name)))

#define offsetof(TYPE, MEMBER)\
    ((size_t) &((TYPE *)0)->MEMBER)

#define list_for_each_entry(pos, head, member)\
    for (pos = list_entry((head)->next, typeof(*pos), member);\
    	&pos->member != (head);\
        pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

static inline void INIT_LIST_HEAD(struct berkly_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void __list_add(struct berkly_head *new,
    struct berkly_head *prev, struct berkly_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

static inline void push_back(struct berkly_head *new, struct berkly_head *head)
{
    __list_add(new, head, head->next);
}

#endif