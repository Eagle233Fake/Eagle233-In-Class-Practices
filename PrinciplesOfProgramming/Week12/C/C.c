#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char str[10000];
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0, j = 0; i < len; j++, i += j)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}