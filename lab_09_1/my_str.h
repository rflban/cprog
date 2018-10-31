#if !defined __MY_STR_H
#define __MY_STR_H

#if !defined size_t
#define __need_size_t
#include <stddef.h>
#undef __need_size_t
#endif

size_t my_strcspn(const char *s, const char *reject);

#endif