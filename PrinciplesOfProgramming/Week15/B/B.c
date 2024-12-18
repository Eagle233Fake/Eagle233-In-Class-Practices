#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int total = 1;
    for (int i = 0; i < n - 1; i++)
    {
        total = (total + 1) * 2;
    }

    printf("%d", total);
}