#ifndef __EXIT_H
#define __EXIT_H

#define __EXIT_SUCCESS 0
#define __EXIT_FAILURE 1
#define __EXIT_NULLPTR 2
#define __EXIT_MEMFAIL 3
#define __EXIT_READERR 4
#define __EXIT_OPENERR 5
#define __EXIT_CLOSERR 6

extern int exit_code;

#ifdef __NEED_PROC_FUNC
void exit_process();
#endif

#endif /*__EXIT_H*/
