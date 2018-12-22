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
#define EXIT_LIBLOAD_ERROR -10

/*!
Выводит в поток error_output сообщение об ошибке, соответствующеее
exit_code и завершает работу программы. Если exit_code равен 0, ничего не делает.

@param error_output [in]
@param exit_code [in]
*/
void exitcode_processing(FILE *error_output, const int exit_code);

/*!
Проверяет правильность использования программы по параметрам командной строки.

@param argc [in]
@param argv [in]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
либо EXIT_USAGE_ERROR_, если переданы неверные параметры.
*/
int usage_check(int argc, char **argv);

#endif
