#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum = 0;
    int n;
    scanf("%d", &n);

    int related = 0;
    int related_7 = 0;
    for (int i = 1; i <= n; i++)
    {
        int digit = 0;
        char number[10];
        sprintf(number, "%d", i);
        while (number[digit] != '\0')
        {
            if (number[digit] == '7')
            {
                related_7 = 1;
                break;
            }
            digit++;
        }
        if (!(i % 7 == 0 || related_7))
        {
            sum += i * i;
        }
        related_7 = 0;
    }

    printf("%d\n", sum);
}