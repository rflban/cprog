// #include <features.h>
// #define __USE_GNU
// #define __BEOS__
#include <stdio.h>
#include <stdlib.h>

#include "exit.h"
#include "file.h"
#include "my_str.h"


int main(int argc, char **argv)
{
    usage_check(argc, argv);
    exit_process(1);

    return __EXIT_SUCCESS;
}