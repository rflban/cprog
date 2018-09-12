#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#include "array_process.h"

#define N1 10
#define N2 50
#define N3 100
#define N4 500
#define N5 1000

unsigned long long tick(void);
void array_fill(numb* array, int len);


int main (void)
{
    numb array1[N1];
    numb array2[N2];
    numb array3[N3];
    numb array4[N4];
    numb array5[N5];
    unsigned long long tb, te;

    setbuf(stdout, NULL);
    srand(time(NULL));

    array_fill(array1, N1);
    array_fill(array2, N2);
    array_fill(array3, N3);
    array_fill(array4, N4);
    array_fill(array5, N5);

    tb  = tick();
    mysort(array1, N1, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    mysort(array2, N2, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    mysort(array3, N3, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    mysort(array4, N4, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    mysort(array5, N5, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    printf("\n");

    tb  = tick();
    qsort(array1, N1, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    qsort(array2, N2, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    qsort(array3, N3, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    qsort(array4, N4, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    tb  = tick();
    qsort(array5, N5, sizeof(numb), comparator);
    te = tick();
    printf("%llu\n", (te - tb));

    return 0;
}


unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void array_fill(numb* array, int len)
{
    for (int i = 0; i < len; i++)
        array[i] = rand();
}
