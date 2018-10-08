#if ! defined __FIO_H
#define __FIO_H

FILE* openf(const char *const name, const char *const mode);
void closef(FILE *file);

#endif
