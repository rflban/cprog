#if ! defined __FIO_H
#define __FIO_H

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

@return Ничего.
*/
void closef(FILE *file);

#endif
