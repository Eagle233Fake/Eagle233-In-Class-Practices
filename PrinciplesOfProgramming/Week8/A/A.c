#include <stdio.h>
#include <string.h>

int main(void)
{
    char n[20];
    scanf("%s", n);

     int length = strlen(n);

    int m;
    for (int i = 0; i < length; i++)
    {
        m = n[i] - '0' - 8;
        if (m >= 0)
        {
            printf("%d", m);
        }
        else
        {
            printf("%d", m + 10);
        }
    }
}