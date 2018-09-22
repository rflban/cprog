#ifndef EXIT_CONTROL_H
#define EXIT_CONTROL_H

#define EXIT_SUCCESS_ 0
#define EXIT_USAGE_ERROR_ -2
#define EXIT_OPEN_ERROR_ -3
#define EXIT_CLOSE_ERROR_ -4
#define EXIT_FILE_CR_ERROR_ -5
#define EXIT_INPUT_ERROR_ -6
#define EXIT_EMPTY_INPUT_ -7
#define EXIT_EMPTY_ARRAY_ -8
#define EXIT_NULL_POINTER_REQ_ -9


void exitcode_processing(FILE* error_output, const int exit_code);
int usage_check(int argc, char **argv);

#endif
