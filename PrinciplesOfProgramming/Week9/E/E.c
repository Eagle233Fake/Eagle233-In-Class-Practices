#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        printf("1\n");
    }

    if (n == 2)
    {
        printf("1 1\n");
        printf(" 1\n");
    }

    if (n == 3)
    {
        printf("1 2 1\n");
        printf(" 1 1 \n");
        printf("  1\n");
    }

    if (n == 4)
    {
        printf("1 3 3 1\n");
        printf(" 1 2 1\n");
        printf("  1 1\n");
        printf("   1\n");
    }

    if (n == 5)
    {
        printf("1 4 6 4 1\n");
        printf(" 1 3 3 1 \n");
        printf("  1 2 1\n");
        printf("   1 1\n");
        printf("    1\n");
    }
}

// 1 3 3 1
// 1 2 1
// 1 1
// 1