#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[500000];
    while (scanf("%s", s) != EOF)
    {
        int length = strlen(s);
        printf("%d\n", length);
    }
}