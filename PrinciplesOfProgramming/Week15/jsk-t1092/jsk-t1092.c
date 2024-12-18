#include <stdio.h>

int main(void)
{
    double prices[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};

    double totalPrice = 0;

    int index = 0;
    while (index < 10)
    {
        int number;
        if (scanf("%d", &number) == 1)
        {
            totalPrice += number * prices[index];
            index++;
        }
        else
        {
            break;
        }
    }
    printf("%.1lf", totalPrice);
}