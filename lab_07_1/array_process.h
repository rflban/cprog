#ifndef ARRAY_PROCESS_H
#define ARRAY_PROCESS_H

#define NUM_FORMAT "%d"

typedef int numb;

int read_array(FILE *source, numb *const pb_src, numb **const pe_src, int len);
int read_array_len(FILE *source, int *const len);
void print_array(FILE *destination, numb *const pb_dst, numb *const pe_dst);
int key(const numb *pb_src, const numb *pe_src, numb **pb_dst, numb **pe_dst);
void mysort(void *base, size_t nitems, size_t size,
    int (*compar)(const void*, const void*));
int comparator(const void*, const void*);
void memory_check(numb *target, const int exit_code);

#endif
