#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double getReal(void)
{
    double a;
    scanf("%lf", &a);
    return a;
}

char *getString(void)
{
    char *b = (char *)malloc(1000001 * sizeof(char));
    scanf("%s", b);
    return b;
}

int main(void)
{
    printf("please input a number:\n");
    double a = getReal();

    printf("please input a string:\n");
    char *b = getString();

    printf("%g\n%s\n", a, b);
    free(b);
}