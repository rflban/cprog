#include <stdio.h>

#include "array_process.h"
#include "file_control.h"
#include "exit_control.h"


int main(int argc, char** argv)
{
    int process_rc;

    process_rc = usage_check(argc);
    exitcode_processing(stderr, process_rc);

    return EXIT_SUCCESS_;
}
