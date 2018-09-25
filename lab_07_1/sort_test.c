#define __USE_MINGW_ANSI_STDIO 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#include "array_process.h"

#define START 0
#define FINISH 10000
#define STEP 10
#define REPEATS 5

unsigned long long tick(void);
void array_fill(numb *array, int len);


int main(void)
{
    FILE *out1, *out2;
    numb array[FINISH] = { 0 };
    unsigned long long tb, te;

    setbuf(stdout, NULL);
    srand(time(NULL));

    out1 = fopen("sort_out_1.txt", "w");
    out2 = fopen("sort_out_2.txt", "w");
    for (int i = START; i <= FINISH; i += STEP)
    {
        unsigned long long tacts;

        tacts = 0;
        for (int j = 0; j < REPEATS; j++)
        {
            array_fill(array, i);
            tb = tick();
            mysort(array, i, sizeof(numb), comparator);
            te = tick();
            tacts += te - tb;
        }
        fprintf(out1, "%llu\n", (tacts / REPEATS));

        tacts = 0;
        for (int j = 0; j < REPEATS; j++)
        {
            array_fill(array, i);
            tb = tick();
            qsort(array, i, sizeof(numb), comparator);
            te = tick();
            tacts += te - tb;
        }
        fprintf(out2, "%llu\n", (tacts / REPEATS));
    }

    fclose(out1);
    fclose(out2);

    return 0;
}


unsigned long long tick(void)
{
    unsigned long long d;
    unsigned long long a;
    __asm__ __volatile__ ("rdtsc" : "=a"(a), "=d"(d));

    return ((d << 32) | a);
}

void array_fill(numb *array, int len)
{
    for (int i = 0; i < len; i++)
        array[i] = rand();
}
