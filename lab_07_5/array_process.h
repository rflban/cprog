#ifndef ARRAY_PROCESS_H
#define ARRAY_PROCESS_H

int read_array(FILE* source, const int* pb_src, const int* pe_src);
int read_array_len(FILE* source, const int* len);
int key(const int* pb_src, const int* pe_src, int** pb_dst, int** pe_dst);
void mysort(void* base, size_t nitems, size_t size, \
            int (*compar)(const void*, const void*))

#endif
