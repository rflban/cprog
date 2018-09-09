#ifndef FILE_CONTROL_H
#define FILE_CONTROL_H

int open_file(FILE** file, const char* const name, const char* const mode);
int close_file(FILE* file);
int carriage_return(FILE* file);

#endif
