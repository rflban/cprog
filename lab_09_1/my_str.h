#if !defined __MY_STR_H
#define __MY_STR_H

// #if !defined size_t
// #define __need_size_t
// #endif /*need size_t*/

// #if !defined NULL
// #define __need_NULL
// #endif /*need NULL*/

#if !defined size_t || !defined NULL
#include <stddef.h>
#endif /*get size_t or get NULL*/


/*!
Вычисляет в байтах длину начального фрагмента последовательности s,
который содержит в себе байты последовательности accept.

@param s [in]
@param accept [in]

@return Возвращает длину в байтах начального фрагмента последовательности s,
который содержит в себе байты последовательности accept.
*/
size_t my_strspn(const char *s, const char *accept);

#endif /*__MY_STR_H*/