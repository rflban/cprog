#include <stdio.h>

#include "fio.h"
#include "matrix.h"
#include "exit.h"


int main(int argc, char **argv)
{
    (void)is_correct_usage(argc, argv);
    exit_process();

    return __EXIT_SUCCESS;
}
