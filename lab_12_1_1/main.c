// Набиев Фарис, ИУ7-33Б.

/*
Алгоритм сортировки №2: Обменом, метод пузырька;
Функция-фильтр №1:
В массиве остаются элементы расположенные между минимальным и максимальным
элементами массива. Если минимальных и/или максимальных элементов несколько, из
берется первый минимальный и первый максимальный элементы. Минимальный и
максимальный элементы в отфильтрованный массив не попадают.
*/

#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"
#include "file_control.h"
#include "exit_control.h"


int main(int argc, char **argv)
{

#if defined (__STATIC__LIB)
#elif defined (__DYNAMIC__LINK__LIB)
#elif defined (__DYNAMIC__LOAD__LIB)

#include <dlfcn.h> 
__LOAD__LIBARRAY();

#endif

    int process_rc;
    int array_len;
    numb *pb_tmp, *pe_tmp;
    numb *pb_array, *pe_array;
    FILE *inputf, *outputf;

    process_rc = usage_check(argc, argv);
    exitcode_processing(stderr, process_rc);

    process_rc = open_file(&inputf, argv[1], "r");
    exitcode_processing(stderr, process_rc);
    process_rc = open_file(&outputf, argv[2], "w");
    exitcode_processing(stderr, process_rc);

    process_rc = read_array_len(inputf, &array_len);
    exitcode_processing(stderr, process_rc);
    process_rc = carriage_return(inputf);
    exitcode_processing(stderr, process_rc);


    switch (argc)
    {
        case 3:
            pb_array = malloc(array_len * sizeof(numb));
            pe_array = pb_array + array_len;

            process_rc = read_array(inputf, pb_array, pe_array);
            memory_check(pb_array, process_rc);
            exitcode_processing(stderr, process_rc);
            
            break;
        case 4:
            pb_tmp = malloc(array_len * sizeof(numb));
            pe_tmp = pb_tmp + array_len;

            process_rc = read_array(inputf, pb_tmp, pe_tmp);
            memory_check(pb_tmp, process_rc);
            exitcode_processing(stderr, process_rc);

            pb_array = malloc(array_len * sizeof(numb));
            if (pb_array == NULL)
            {
                free(pb_tmp);
                exitcode_processing(stderr, EXIT_NULL_POINTER_REQ_);
            }

            process_rc = key(pb_tmp, pe_tmp, &pb_array, &pe_array);
            free(pb_tmp);
            exitcode_processing(stderr, process_rc);

            break;
    }

    mysort(pb_array, (pe_array - pb_array), sizeof(numb), comparator);
    print_array(outputf, pb_array, pe_array);

    free(pb_array);
    process_rc = close_file(inputf);
    exitcode_processing(stderr, process_rc);
    process_rc = close_file(outputf);
    exitcode_processing(stderr, process_rc);

    return EXIT_SUCCESS_;
}
