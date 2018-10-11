#include <stdio.h>

#include "fio.h"
#include "matrix.h"
#include "exit.h"
#include "ref.h"
#include "actions.h"
#include "matrix_operations.h"
    

int main(int argc, char **argv)
{
    matrix a = NULL;
    matrix b = NULL;
    FILE *src_a = NULL;
    FILE *src_b = NULL;
    FILE *dst_res = NULL;

    setbuf(stdout, NULL);

    // src_a = fopen("in_3.txt", "r");
    // a = read_matrix(src_a);
    // printf("%g\n", matrix_determinant(a));
    // matrix_free(a);

    (void)is_correct_usage(argc, argv);
    exit_process();

    if (argv[1][0] != 'h')
    {
        src_a = openf(argv[2], "r");
        exit_process();
        a = read_matrix(src_a);
        exit_process();
        closef(src_a);
        memory_check(a);
        exit_process();

        if (argv[1][0] != 'o')
        {
            src_b = openf(argv[3], "r");
            memory_check(a);
            exit_process();
            b = read_matrix(src_b);
            memory_check(a);
            exit_process();
            closef(src_b);
            memory_check(a);
            memory_check(b);
            exit_process();

            dst_res = openf(argv[4], "w");
            memory_check(a);
            memory_check(b);
            exit_process();
        }
        else
        {
            dst_res = openf(argv[3], "w");
            memory_check(a);
            exit_process();
        }
    }

    memory_check(a);
    memory_check(b);
    exit_process();
    carry_out(dst_res, argv[1][0], a, b);
    matrix_free(a);
    matrix_free(b);
    exit_process();
    closef(dst_res);
    exit_process();

    return __EXIT_SUCCESS;
}
