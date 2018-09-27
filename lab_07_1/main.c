#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"
#include "file_control.h"
#include "exit_control.h"


int main(int argc, char **argv)
{
    int process_rc;
    int array_len;
    numb *pb_tmp, *pe_tmp;
    numb *pb_array, *pe_array;
    FILE *inputf, *outputf;

    setbuf(stdout, NULL);

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

    if (argc == 3)
    {
        pb_array = malloc(array_len * sizeof(numb));
        pe_array = pb_array + array_len;
        process_rc = read_array(inputf, pb_array, pe_array);
        memory_check(pb_array, process_rc);
        exitcode_processing(stderr, process_rc);
    }
    else
    {
        if (!(argv[3][0] == 'f' && argv[3][1] == 0))
            exitcode_processing(stderr, EXIT_USAGE_ERROR_);
        pb_tmp = malloc(array_len * sizeof(numb));
        pe_tmp = pb_tmp + array_len;
        process_rc = read_array(inputf, pb_tmp, pe_tmp);
        memory_check(pb_tmp, process_rc);
        exitcode_processing(stderr, process_rc);
        process_rc = key(pb_tmp, pe_tmp, &pb_array, &pe_array);
        free(pb_tmp);
        exitcode_processing(stderr, process_rc);
    }

    mysort(pb_array, (pe_array - pb_array), sizeof(numb), comparator);
    print_array(outputf, pb_array, pe_array);

    process_rc = close_file(inputf);
    memory_check(pb_array, process_rc);
    exitcode_processing(stderr, process_rc);
    process_rc = close_file(outputf);
    memory_check(pb_array, process_rc);
    exitcode_processing(stderr, process_rc);
    free(pb_array);

    return EXIT_SUCCESS_;
}
