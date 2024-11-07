#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    float bike = 27 + 23 + n / 3.0;

    float walk = n / 1.2;

    if (bike < walk)
    {
        printf("Bike\n");
    }
    else if (bike > walk)
    {
        printf("Walk\n");
    }
    else
    {
        printf("All\n");
    }
}