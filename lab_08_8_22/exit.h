#if ! defined __EXIT_H
#define __EXIT_H

#define __EXIT_SUCCESS 0
#define __EXIT_INVALID_USAGE -2
#define __EXIT_OPEN_ERROR -3
#define __EXIT_CLOSE_ERROR -4
#define __EXIT_INVALID_INPUT -5
#define __EXIT_EMPTY_INPUT -6
#define __EXIT_NULL_POINTER_REQ -7

void exit_process();
int is_correct_usage(int argc, char **argv);

extern int exit_code;

#endif
