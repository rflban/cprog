#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    int rc;
    int n1, n2;
    char buf;

    printf("Enter first number: ");
    while(((rc = scanf("%d%c", &n1, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    buf = '3';
    printf("Enter second number: ");
    while(((rc = scanf("%d%c", &n2, &buf)) != 2 && rc != EOF) || buf != '\n')
    {
        printf("Input error. Try again: ");

        do
        {
            rc = scanf("%c", &buf);
        }
        while(rc != EOF && buf != '\n');
    }

    printf("GCD = %d", gcd(n1,n2));
    return 0;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}
