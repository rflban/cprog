#if ! defined __REF_H
#define __REF_H

/*!
Проверяет правильность использования программы по параметрам командной строки.

@param argc [in]
@param argv [in]

@return Ничего.
*/
int is_correct_usage(int argc, char **argv);

/*!
Показывает справочную информацию

@return Ничего.
*/
void show_help();

#endif
