#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char str[6];
    sprintf(str, "%d", n);

    printf("%d", strlen(str));
}