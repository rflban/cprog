#ifndef MATRIX_H
#define MATRIX_H

#define MAX_SIDE_LEN 100

int get_element(double* a, int len, int ind1, int ind2, double* number);
int set_element(double* a, int len, int ind1, int ind2, double number);
int find_min_saddle(double* a, int len, double* min_saddle);
void matrix_mulp(double* a, double* b, double*c, int len);
void print_matrix(double* a, int len);

#endif
