#if !defined __REWRITE_H
#define __REWRITE_H

#include "exit.h"
#include "my_str.h"

/*!
Перезаписывает данные из потока source в destination,
заменяя строки search на replace.

@param source [in]
@param destination [out]
@param search [in]
@param replace [in]

@return Ничего не возвращает.
*/
void rewrite(FILE *source, FILE *destination, const char *search, const char *replace);

#endif /*__REWRITE_H*/