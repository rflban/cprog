#if !defined __FILE_H
#define __FILE_H

#include <stdio.h>

#include "exit.h"

/*!
Открывает файл с именем name в режиме mode.

@param name [in]
@param mode [in]

@return Возвращает файловую перменную, указывающюю на открытый файл.
*/
FILE *openf(const char *const name, const char *const mode);

/*!
Закрывает файл по параметру file.

@param file [in]

@return Ничего не возваращет.
*/
void closef(FILE *file);

#endif /*__FILE_H*/