/*
Набиев Фарис. ИУ7-23Б;
В качестве основного целочисленного типа выбран signed long int;
Сортировка пузырьком, по возрастанию;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define RETURN_SUCCESS_ 0
#define RETURN_USAGE_ERROR_ -1
#define RETURN_OPEN_ERROR_ -2
#define RETURN_CLOSE_ERROR_ -3
#define RETURN_SEEK_ERROR_ -4
#define RETURN_INVALID_COMMAND_ -5
#define EXIT_SUCCESS_ 0
#define EXIT_USAGE_ERROR_ -1
#define EXIT_OPEN_ERROR_ -2
#define EXIT_CLOSE_ERROR_ -3
#define EXIT_SEEK_ERROR_ -4
#define EXIT_INVALID_COMMAND_ -5

#define N_RAND_MIN -100
#define N_RAND_MAX 100
#define RANDSEQ_LEN 15

int randint(int a, int b);
int compare(int num1, int num2);

int get_number_by_pos(FILE * target, int * number, int pos);
int put_number_by_pos(FILE * target, int * number, int pos);
int sort_object(FILE * target, FILE * output);
void create_object(FILE * target, int randmin, int randmax, int n);
void print_object(FILE * target, FILE * output);
void print_procces_error(int exit_code, FILE * err_output);
void show_example();

int main(int argc, char ** argv)
{
    FILE * output = stdout;
    FILE * err_output = stderr;
    FILE * data_file;
    char * open_mode;
    int proccess_rc = 0;

    srand(time(NULL));

    if (argc != 3)
    {
        proccess_rc = EXIT_USAGE_ERROR_;
        goto END;
    }

    if (strcmp(argv[1], "create") == 0)
        open_mode = "wb";
    else if (strcmp(argv[1], "print") == 0)
        open_mode = "rb";
    else if (strcmp(argv[1], "sort") == 0)
        open_mode = "rb+";
    else
    {
        proccess_rc = EXIT_INVALID_COMMAND_;
        goto END;
    }

    data_file = fopen(argv[2], open_mode);
    if(data_file == NULL)
    {
        proccess_rc = EXIT_OPEN_ERROR_;
        goto END;
    }

    if (strcmp(argv[1], "create") == 0)
        create_object(data_file, N_RAND_MIN, N_RAND_MAX, RANDSEQ_LEN);
    else if (strcmp(argv[1], "print") == 0)
        print_object(data_file, output);
    else if (strcmp(argv[1], "sort") == 0)
        proccess_rc = sort_object(data_file, output);

    if (fclose(data_file) != 0)
        proccess_rc = EXIT_CLOSE_ERROR_;

    END:
    print_procces_error(proccess_rc, err_output);
    return RETURN_SUCCESS_;
}

void show_example()
{
    printf("example.exe <command_marker> <file_name>\n\n"
           "Commands list:\n"
           "`create` - Create a file and fill it by random intrgers;\n"
           "`print` - Print digit numbers from a file;\n"
           "`sort` - Sort numbers in a file;\n");
}

int randint(int a, int b)
{
    return a + (rand()%(b - a + 1));
}

int compare(int num1, int num2)
{
    if (num1 > num2)
        return 1;
    return 0;
}

int get_number_by_pos(FILE * target, int * number, int pos)
{
    int proccess_rc;
    
    proccess_rc = fseek(target, sizeof(*number)*pos, SEEK_SET);
    if (proccess_rc == 0)
        fread(number, sizeof(*number), 1, target);
    
    return proccess_rc;
}

int put_number_by_pos(FILE * target, int * number, int pos)
{
    int proccess_rc;
    
    proccess_rc = fseek(target, sizeof(*number)*pos, SEEK_SET);
    if (proccess_rc == 0)
        fwrite(number, sizeof(*number), 1, target);
    
    return proccess_rc;
}

void create_object(FILE * target, int randmin, int randmax, int n)
{
    for (int i = 0; i < n; i++)
    {
        int number = randint(randmin, randmax);
        fwrite(&number, sizeof(number), 1, target);
    }
}

void print_object(FILE * target, FILE * output)
{
    size_t read;
    int number;

    read = fread(&number, sizeof(number), 1, target);
    while(read == 1)
    {
        fprintf(output, "%d ", number);
        read = fread(&number, sizeof(number), 1, target);
    }
}

int sort_object(FILE * target, FILE * output)
{
    int n = 0;
    int flag = 0;
    int c_number, n_number;
    int proccess_rc = EXIT_SUCCESS_;
    
    proccess_rc = fseek(target, 0, SEEK_END);
    if (proccess_rc != 0)
    {
        proccess_rc = EXIT_SEEK_ERROR_;
        goto END;
    }
    n = ftell(target) / sizeof(int);

    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            proccess_rc = get_number_by_pos(target, &c_number, i);
            if (proccess_rc != 0)
            {
                proccess_rc = EXIT_SEEK_ERROR_;
                goto END;
            }
            proccess_rc = get_number_by_pos(target, &n_number, i+1);
            if (proccess_rc != 0)
            {
                proccess_rc = EXIT_SEEK_ERROR_;
                goto END;
            }
            if (compare(c_number, n_number))
            {
                flag = 1;
                proccess_rc = put_number_by_pos(target, &n_number, i);
                if (proccess_rc != 0)
                {
                    proccess_rc = EXIT_SEEK_ERROR_;
                    goto END;
                }
                proccess_rc = put_number_by_pos(target, &c_number, i+1);
                if (proccess_rc != 0)
                {
                    proccess_rc = EXIT_SEEK_ERROR_;
                    goto END;
                }
            }
        }
        if (!flag)
            break;
    }
    
    END: return proccess_rc;
}

void print_procces_error(int exit_code, FILE * err_output)
{
    switch (exit_code)
    {
        case EXIT_USAGE_ERROR_: 
            show_example();
            fprintf(err_output, "Error. Wrong amount of arguments.");
            exit(RETURN_USAGE_ERROR_);
            break;
            
        case EXIT_OPEN_ERROR_:
            fprintf(err_output, "Error. Could not open file:\n%s.",
                    strerror(errno));
            exit(RETURN_OPEN_ERROR_);
            break;
            
        case EXIT_CLOSE_ERROR_:
            fprintf(err_output, "File closing error");
            exit(RETURN_CLOSE_ERROR_);
            break;
            
        case EXIT_SEEK_ERROR_:
            fprintf(err_output, "File reading error");
            exit(RETURN_SEEK_ERROR_);
            break;
        
        case EXIT_INVALID_COMMAND_:
            fprintf(err_output, "Error. Invalid command marker.");
            exit(RETURN_INVALID_COMMAND_);
            break;
    }
}