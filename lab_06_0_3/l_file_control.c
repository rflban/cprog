#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "l_file_control.h"
#include "l_exit_control.h"


void close_file(FILE* file, FILE* err_output)
{
    int proccess_rc = fclose(file);
    if (proccess_rc == EOF)
    {
        fprintf(err_output,
                "\nError. Could not close this file:\n%s.\n",
                strerror(errno));

        exit(RETURN_CLOSE_ERROR_);
    }
}
