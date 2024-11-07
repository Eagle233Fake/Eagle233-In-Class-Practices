#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            printf("%d/2=%d\n", n * 2, n);
        }
        else
        {
            n = n * 3 + 1;
            printf("%d*3+1=%d\n", (n - 1) / 3, n);
        }
    }
    printf("End\n");
}