#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[1000000];

    scanf("%s", str);

    int len = strlen(str);
    for (int i = len - 2; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}