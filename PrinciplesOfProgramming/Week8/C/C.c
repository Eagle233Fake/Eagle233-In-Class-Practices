#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    for (int i = 0; i < 3; i++)
    {
        for (int j = -i + 2; j > 0; j--)
        {
            printf(" ");
        }
        for (int j = 2 * i + 1; j > 0; j--)
        {
            printf("%c", c);
        }
        for (int j = -i + 2; j > 0; j--)
        {
            printf(" ");
        }
        printf("\n");
    }
}