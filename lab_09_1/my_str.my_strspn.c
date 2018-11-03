#include "my_str.h"

size_t my_strspn(const char *s, const char *accept)
{
    if (*s == '\0' || *accept == '\0')
        return 0;

    size_t count;
    const char *cur_char;
    const char *cur_accept;

    count = 0;
    cur_char = s;
    cur_accept = accept;

    while (*cur_char != '\0')
    {
        int flag_accept = 0;

        while (*cur_accept != '\0')
        {
            if (*cur_char == *cur_accept)
                flag_accept = 1;
        
            cur_accept++;
        }
        cur_accept = accept;

        if (!flag_accept)
            break;

        count += sizeof(char);
        cur_char++;
    }

    return count;
}