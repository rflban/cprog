#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "mylib.h"

#define __NEED_PROC_FUNC
#include "exit.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        exit_code = __EXIT_FAILURE;
        fprintf(stderr, "Invalid usage. Rerun:\n%s <input-file>\n", argv[0]);
        exit_process();
    }

    FILE *inputs;
    struct list_head head;

    INIT_LIST_HEAD(&head);

    inputs = fopen(argv[1], "r");

    if (inputs == NULL)
    {
        exit_code = __EXIT_OPENERR;
        exit_process();
    }

    read_data(inputs, &head);
    exit_process();

    if (fclose(inputs) != 0)
    {
        exit_code = __EXIT_CLOSERR;
        exit_process();
    }

    log_temperature_dif(&head);
    exit_process();

    free_data(&head);

    return EXIT_SUCCESS;
}
