#include <stdio.h>

int main(void)
{
    long long a, b;

    scanf("%lld %lld", &a, &b);
    int m = a;
    for (int i = 0; i < b - 1; i++)
    {
        m = ((m % 7) * (a % 7)) % 7;
    }

    if (m == 1)
    {
        printf("Monday\n");
    }
    else if (m == 2)
    {
        printf("Tuesday\n");
    }
    else if (m == 3)
    {
        printf("Wednesday\n");
    }
    else if (m == 4)
    {
        printf("Thursday\n");
    }
    else if (m == 5)
    {
        printf("Friday\n");
    }
    else if (m == 6)
    {
        printf("Saturday\n");
    }
    else if (m == 0)
    {
        printf("Sunday\n");
    }
}
