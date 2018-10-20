#if ! defined __EXIT_H
#define __EXIT_H

#define __EXIT_SUCCESS 0
#define __EXIT_INVALID_USAGE -2
#define __EXIT_OPEN_ERROR -3
#define __EXIT_CLOSE_ERROR -4
#define __EXIT_INVALID_INPUT -5
#define __EXIT_EMPTY_INPUT -6
#define __EXIT_NULL_POINTER_REQ -7
#define __EXIT_ALLOC_ERROR -8
#define __EXIT_INVALID_DATA -9
#define __EXIT_MATRICES_SIZE_MISMATCH -10

/*!
Обратобка коды выхода из последнего процесса exit_code.

@return Ничего.
*/
void exit_process();

extern int exit_code;

#endif
