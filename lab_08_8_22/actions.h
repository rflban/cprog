#if ! defined __ACTIONS_H
#define __ACTIONS_H

#include "matrix.h"

void action_a(FILE *outputf, matrix a, matrix b);
void action_m(FILE *outputf, matrix a, matrix b);
void action_o(FILE *outputf, matrix a);
void action_h();
void carry_out(FILE *outputf, char action, matrix a, matrix b);

#endif
