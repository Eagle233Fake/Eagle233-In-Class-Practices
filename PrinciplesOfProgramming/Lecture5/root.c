#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define ARGC_LENGTH 4

// Usage: ./root a b c

int main(int argc, char *argv[])
{
    if (argc != ARGC_LENGTH)
    {
        printf("Usage: ./root a b c\n");
        return 1;
    }

    /* 
    for (int i = 1; i < ARGC_LENGTH; i++)
    {
        if (isdigit(argv[i]) == 0)
        {
            printf("Please enter three valid digits.\n");
            return 1;
        }
    }
    */
    
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);

    double delta = b * b - 4 * a * c;
    
    double result_1, result_2;
    if (delta == 0)
    {
        result_1 = -b / (2 * a);
        printf("%lf\n", result_1);
    }

    if (delta > 0)
    {
        result_1 = (-b + sqrt(delta)) / (2 * a);
        result_2 = (-b - sqrt(delta)) / (2 * a);
        printf("%lf %lf\n", result_1, result_2);
    }

    if (delta < 0)
    {
        result_1 = -b / (2 * a);
        result_2 = -b / (2 * a);
        printf("%lf+%lfi %lf-%lfi\n", result_1, sqrt(-delta), result_2, sqrt(-delta));
    }
}