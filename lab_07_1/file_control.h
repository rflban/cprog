#ifndef FILE_CONTROL_H
#define FILE_CONTROL_H

/*!
Открывает файл с именем name в переменную file в режиме mode.

@param file [out]
@param name [in]
@param mode [in]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
либо EXIT_OPEN_ERROR_, если файл открыть не удалось.
*/
int open_file(FILE **file, const char *const name, const char *const mode);

/*!
Закрывает файл по параметру file.

@param file [in]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
либо EXIT_CLOSE_ERROR_, если файл закрыть не удалось.
*/
int close_file(FILE *file);

/*!
Возвращает указатель чтения файла переменной file в начало.

@param file [in]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
либо EXIT_FILE_CR_ERROR_, если вернуть указатель не удалось.
*/
int carriage_return(FILE *file);

#endif
