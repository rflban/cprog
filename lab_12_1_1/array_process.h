#ifndef ARRAY_PROCESS_H
#define ARRAY_PROCESS_H

#define NUM_FORMAT "%d"

typedef int numb;

/*!
Считывает из потока source целые числа и записывает их по указателю
от pb_src до pe_src.

@param source [in]
@param pb_src [in, out]
@param pe_src [in, out]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
EXIT_INPUT_ERROR_, произошел некорректный ввод,
EXIT_EMPTY_INPUT_, если ввод оказался пустым.
*/
int read_array(FILE *source, numb *const pb_src, numb *const pe_src);

/*!
Считывает из потока source целые числа, подсчитывает их кол-во и записывает его в len.

@param source [in]
@param len [out]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
EXIT_INPUT_ERROR_, произошел некорректный ввод.
*/
int read_array_len(FILE *source, int *const len);

/*!
Выводит в поток destination целые числа по указателю
от pb_dst до pe_dst.

@param destination [in]
@param pb_dst [in]
@param pe_dst [in]
*/
void print_array(FILE *destination, numb *const pb_dst, numb *const pe_dst);

/*!
Копирует из области памяти целые числа, которые расположены между
максимальным и минимальным элементами в этой области, по указателю
от pb_src до pb_dst в заранее созданную область в pb_dst, 
записывая ее конец в pe_dst.

@param pb_src [in]
@param pe_src [in]
@param pb_dst [out]
@param pe_dst [out]

@return Возвращает EXIT_SUCCESS_, если ошибок не было,
EXIT_EMPTY_ARRAY_, если отфильтрованный массив получается пустым,
EXIT_NULL_POINTER_REQ_, если произошло обращение к нулевому указателю.
*/
int key(const numb *pb_src, const numb *pe_src, numb **pb_dst, numb **pe_dst);

/*!
Сортирует область памяти, начиная с base, из nitems элементов размера size.

@param base [in, out]
@param nitems [in]
@param size [in]
*/
void mysort(void *base, size_t nitems, size_t size,
    int (*compar)(const void*, const void*));

/*!
Функция сравнения для универсальной сортировки. Для целых чисел типа int.

@return Возвращает <0, если правый параметр имеет меньшую ценность, чем левый,
0, если их ценность равна,
>0 если ценность правого выше, чем ценность левого.
*/
int comparator(const void*, const void*);

/*!
Очищает память по указателю target, если код выхода exit_code не успешен.

@param target [in]
@param exit_code [in]
*/
void memory_check(numb *target, const int exit_code);

#endif
