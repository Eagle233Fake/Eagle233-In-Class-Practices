#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    printf("  %c  \n", c);
    printf(" %c%c%c \n", c, c, c);
    printf("%c%c%c%c%c\n", c, c, c, c, c);
    printf(" %c%c%c \n", c, c, c);
    printf("  %c  \n", c);
}