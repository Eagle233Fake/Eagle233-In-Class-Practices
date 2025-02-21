#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    if (isPrime(n))
    {
        printf("%d=%d\n", n, n);
    }
    else
    {
        printf("%d=", n);
        bool isFirst = true;
        for (int i = 2; i * i <= n; i++)
        {
            while ((n % i == 0))
            {
                if (isFirst)
                {
                    printf("%d", i);
                    isFirst = false;
                }
                else
                {
                    printf("*%d", i);
                }
                n /= i;
            }
        }
        if (n != 1)
        {
            if (isFirst)
            {
                printf("%d", n);
            }
            else
            {
                printf("*%d", n);
            }
            
        }
        printf("\n");
    }


}

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

