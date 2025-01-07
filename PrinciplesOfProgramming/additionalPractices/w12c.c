#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    for (int i = 0, j = 1; i < n; i += j, j++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}