#ifndef __EXIT_H
#define __EXIT_H

#include <stdio.h>
#include <stdlib.h>

#define __EXIT_SUCCESS 0
#define __EXIT_MEM_ERR 2
#define __EXIT_INV_INP 3
#define __EXIT_NUL_REQ 4

extern int exit_code;

void exit_proccess();

#endif 