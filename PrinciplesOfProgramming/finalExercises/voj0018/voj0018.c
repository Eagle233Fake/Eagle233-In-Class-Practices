#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int remain = 1;
    for (int i = 0; i < n - 1; i++)
    {
        remain = (remain + 1) * 2;
    }

    printf("%d", remain);
}