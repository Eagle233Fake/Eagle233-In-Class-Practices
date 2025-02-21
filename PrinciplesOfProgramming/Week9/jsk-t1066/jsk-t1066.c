#include <stdio.h>

int main(void)
{
    int number[50];
    number[0] = 1, number[1] = 1;

    for (int i = 2; i <= 49; i++)
    {
        number[i] = number[i - 1] + number[i - 2];
    }

    int n;
    scanf("%d", &n);
    printf("%d\n", number[n - 1]);
}