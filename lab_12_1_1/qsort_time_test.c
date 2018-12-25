#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "array_process.h"

#define START 0
#define FINISH 10000000
#define STEP 10
#define REPEATS 1

unsigned long long tick(void);
void array_fill(numb *array, int len, int state);


int main(int argc, char **argv)
{

#if defined (__STATIC__LIB)
#elif defined (__DYNAMIC__LINK__LIB)
#elif defined (__DYNAMIC__LOAD__LIB)

#include <dlfcn.h> 
__LOAD__LIBARRAY();

#endif

    int state = 0;
    FILE *out1;
    numb *array = malloc(sizeof(numb) * FINISH);
    unsigned long long tb, te;

    setbuf(stdout, NULL);
    srand(time(NULL));

    if (argc == 2)
        state = atoi(argv[1]);

    out1 = fopen("qsort_time_res.txt", "w");

    printf("Fill type: %d.\n", state);
    for (int i = START; i <= FINISH; i += STEP)
    {
        unsigned long long tacts;

        tacts = 0;
        for (int j = 0; j < REPEATS; j++)
        {
            array_fill(array, i, state);
            tb = tick();
            qsort(array, i, sizeof(numb), comparator);
            te = tick();
            tacts += te - tb;
        }
        fprintf(out1, "%d %llu\n", i, (tacts / REPEATS));
    }

    fclose(out1);
    free(array);

    return 0;
}

/*
EAX -> a
EDX -> d
*/
unsigned long long tick(void)
{
    unsigned long long a;
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=a"(a), "=d"(d));

    return ((d << 32) | a);
}

/*
state:
-1 - по возрастанию
0 - произвольно
1 - по убыванию
*/
void array_fill(numb *array, int len, int state)
{
    for (int i = 0; i < len; i++)
    {
        switch (state)
        {
            case -1:
                array[i] = i;
                break;
            case 0:
                array[i] = rand();
                break;
            case 1:
                array[i] = len - i;
                break;
            default:
                array[i] = 0;
                break;
        }
    }
}
