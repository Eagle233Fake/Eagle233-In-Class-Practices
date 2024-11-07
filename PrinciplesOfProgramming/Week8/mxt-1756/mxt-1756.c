#include <stdio.h>

int main(void)
{
    float x;
    scanf("%f", &x);

    if (x >= 0 && x < 5)
    {
        printf("%.3f\n", -x + 2.5);
    }

    else if (x >= 5 && x < 10)
    {
        printf("%.3f\n", 2 - 1.5 * (x - 3) * (x - 3));
    }

    else if (x >= 10 && x < 20)
    {
        printf("%.3f\n", x / 2 - 1.5);
    }
}