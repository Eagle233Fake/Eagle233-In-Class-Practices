#include <stdio.h>

int main(void)
{
    int high, up, down;
    scanf("%d %d %d", &high, &up, &down);

    int days = 1;
    while (high > 0)
    {
        high -= up;
        if (high > 0)
        {
            high += down;
        }
        else
        {
            break;
        }

        days++;
    }

    printf("%d\n", days);
}