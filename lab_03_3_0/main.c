#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

/*
 * В качестве основного целочисленного типа выбран signed long int;
 * Сортировка пузырьком, по возрастанию;
*/

#define _RAND_MIN -100
#define _RAND_MAX 100
#define _RANDSEQ_LEN 15

int randint(int a, int b);
int get_number_by_pos();
int put_number_by_pos();
int compare(int num1, int num2);

void create_object(FILE * target, int randmin, int randmax, int n);
void print_object(FILE * target, FILE * output);
void sort_object(FILE * target, char target_name[],
                 FILE * output, int (* comp)(int, int));
void show_example();

int main(int argc, char ** argv)
{
    FILE * output = stdout;
    FILE * err_output = stderr;
    FILE * data_file;
    char * open_mode;

    srand(time(NULL));

    if (argc != 3)
    {
        show_example();
        goto END;
    }

    if (strcmp(argv[1], "create") == 0)
        open_mode = "wb";
    else if (strcmp(argv[1], "print") == 0)
        open_mode = "rb";
    else if (strcmp(argv[1], "sort") == 0)
        open_mode = "r  b";
    else
    {
        fprintf(err_output, "Error. Invalid command marker.");
        goto END;
    }

    data_file = fopen(argv[2], open_mode);
    if(data_file == NULL)
    {
        fprintf(err_output, "Error. Could not open `%s`:\n%s",
                argv[2], strerror(errno));
        goto END;
    }

    if (strcmp(argv[1], "create") == 0)
        create_object(data_file, _RAND_MIN, _RAND_MAX, _RANDSEQ_LEN);
    else if (strcmp(argv[1], "print") == 0)
        print_object(data_file, output);
    else if (strcmp(argv[1], "sort") == 0)
    {
        sort_object(data_file, argv[2], output, &compare);
        goto END;
    }

    fclose(data_file);

    END: return 0;
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

int get_number_by_pos(char target_name[], int * number, int pos)
{
    int return_code;
    FILE * target = fopen(target_name, "rb");

    (void)fseek(target, sizeof(*number)*pos, SEEK_SET);
    return_code = fread(number, sizeof(*number), 1, target);

    fclose(target);

    return return_code;
}

int put_number_by_pos(char target_name[], int * number, int pos, int len)
{
    int return_code;
    int num;
    int buffer[BUFSIZ];
    FILE * target = fopen(target_name, "rb");
    fread(buffer, sizeof(num), len, target);

    buffer[pos] = *number;
    fclose(target);

    target = fopen(target_name, "wb");
    for (int i = 0; i < len; i++)
        return_code = fwrite(&buffer[i], sizeof(*number), 1, target);

    fclose(target);

    return return_code;
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

void sort_object(FILE * target, char target_name[],
                 FILE * output, int (* comp)(int, int))
{
    size_t read;
    int number;
    int n = 0;

    read = fread(&number, sizeof(number), 1, target);
    while(read == 1)
    {
        n++;
        read = fread(&number, sizeof(number), 1, target);
    }

    fclose(target);

    for (int j = 0; j < n-1; j++)
    {
        int flag = 0;
        for (int i = 0; i < n-1; i++)
        {
            int c_number, n_number;
            get_number_by_pos(target_name, &c_number, i);
            get_number_by_pos(target_name, &n_number, i+1);
            if ((*comp)(c_number, n_number))
            {
                flag = 1;
                put_number_by_pos(target_name, &n_number, i, n);
                put_number_by_pos(target_name, &c_number, i+1, n);
            }
        }
        if (!flag)
            break;
    }
}
