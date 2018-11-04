#if !defined __MY_STR_H
#define __MY_STR_H

#if !defined size_t
#define __need_size_t
#endif /*need size_t*/

#if !defined NULL
#define __need_NULL
#endif /*need NULL*/

#if !defined size_t || !defined NULL
#include <stddef.h>
#endif /*get size_t or get NULL*/

size_t my_strspn(const char *s, const char *reject);

#endif /*__MY_STR_H*/