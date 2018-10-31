#include "my_str.h"

#if !defined NULL
#define __need_NULL
#include <stddef.h>
#undef __need_NULL
#endif

size_t my_strcspn(const char *s, const char *reject)
{
    if (s == NULL || reject == NULL)
        return 0;

    size_t count;
    const char *cur_char;
    const char *cur_reject;

    count = 0;
    cur_char = s;
    cur_reject = reject;

    while (*cur_char != '\0')
    {
        while (*cur_reject != '\0')
        {
            if (*cur_char == *cur_reject)
                return count;
        
            cur_reject++;
        }
        cur_reject = reject;

        count += sizeof(char);
        cur_char++;
    }

    return count;
}