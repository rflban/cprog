#include <stdio.h>

#define _RETURN_SUCCESS_ 0
#define _RETURN_FAILURE_ -1

#define _EXIT_SUCCESS_ 0

int gcd(int a, int b);
int int_input(int * number, char start_message[], char error_message[]);


int main(void)
{
    int n1, n2;
    int input_state;

    input_state = int_input(&n1, "Enter first number: ", 
							"Input error. Try again: ");
    if (input_state == EOF)
    {
        printf("Error. End of file was reached too early.");
        return _RETURN_FAILURE_;
    }

    input_state = int_input(&n2, "Enter second number: ", 
							"Input error. Try again: ");
    if (input_state == EOF)
    {
        printf("Error. End of file was reached too early.");
        return _RETURN_FAILURE_;
    }

    printf("GCD = %d", gcd(n1,n2));
    return _RETURN_SUCCESS_;
}

int int_input(int * number, char start_message[], char error_message[])
{
    int rc;
    char buf;

    printf("%s", start_message);
    while(( ( rc = scanf("%d%c", number, &buf) ) != 2 || buf != '\n') && rc != EOF)
    {
        printf("%s", error_message);

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    if (rc != EOF)
        return _EXIT_SUCCESS_;
    return rc;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}
