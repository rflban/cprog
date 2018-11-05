/*
Nabiev Faris. IU7-33B. Var 16/2.
*/

#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "file.h"
#include "my_str.h"
#include "rewrite.h"


int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    usage_check(argc, argv);
    exit_process(1);
    exit_process(1);

    FILE * inputf;
    FILE * outputf;

    inputf = openf(argv[1], "r");
    exit_process(1);
    outputf = openf(argv[2], "w");
    exit_process(1);

    rewrite(inputf, outputf, argv[4], argv[6]);
    exit_process(1);

    closef(inputf);
    exit_process(1);
    closef(outputf);
    exit_process(1);

    return __EXIT_SUCCESS;
}