#include <stdio.h>
#include <stdlib.h>

#include "array_process.h"
#include "file_control.h"
#include "exit_control.h"


int main(int argc, char** argv)
{
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

    pb_tmp = malloc(array_len*sizeof(numb));
    pe_tmp = pb_tmp + array_len - 1;
    read_array(inputf, pb_tmp, pe_tmp);
    print_array(outputf, pb_tmp, pe_tmp);
    free(pb_tmp);

    process_rc = close_file(inputf);
    exitcode_processing(stderr, process_rc);
    process_rc = close_file(outputf);
    exitcode_processing(stderr, process_rc);

    return EXIT_SUCCESS_;
}
