#if !defined __EXIT_H
#define __EXIT_H

#define __EXIT_SUCCESS 0 

extern int exit_code;

void exit_process();
void usage_check(const int argc, const char **argv);

#endif /*__EXIT_H*/