#if !defined __MY_STR_H
#define __MY_STR_H 1

#if !defined size_t
#define __need_size_t
#include <stddef.h>
#endif /*size_t*/

size_t my_strcspn(const char *s, const char *reject);

#endif /*__MY_STR_H*/