#include <stdio.h>
#define INPUT_ERROR_M "Input error. Try again: "
#define EOF_ERROR_M "Error. End of file was reached too early."

int gcd(int a, int b);

int int_input(int * number, char start_message[], char error_message[]);

int main(void)
{
    int n1, n2;
    int input_state;

    input_state = int_input(&n1, "Enter first number: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    input_state = int_input(&n2, "Enter second number: ", INPUT_ERROR_M);
    if (input_state == EOF)
    {
        printf(EOF_ERROR_M);
        return 0;
    }

    printf("GCD = %d", gcd(n1,n2));
    return 0;
}

int int_input(int * number, char start_message[], char error_message[])
{
    int rc;
    char buf;

    printf(start_message);
    while(( ( rc = scanf("%d%c", number, &buf) ) != 2 || buf != '\n') && rc != EOF)
    {
        printf(error_message);

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    if (rc == EOF)
        return EOF;
    return 0;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}
