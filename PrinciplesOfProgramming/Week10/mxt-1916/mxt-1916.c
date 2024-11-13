#include <stdio.h>
#include <string.h>

int Digit(int n, int k);

int main(void)
{
    int n;
    int digit;
    scanf("%d %d", &n, &digit);

    printf("%d", Digit(n, digit));
}

int Digit(int n, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        n /= 10;
    }
    return n % 10;
}