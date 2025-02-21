#include <stdio.h>

double upper(double n);
double lower(double n);

int main(void)
{
    int n;
    scanf("%d", &n);

    double sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        double up = upper(i);
        double low = lower(i);
        sum += (double)up / (double)low;
    }

    printf("%.2lf", sum);
}

double upper(double n)
{
    if (n == 1)
    {
        return 2;
    }
    if (n == 2)
    {
        return 3;
    }
    else
    {
        return upper(n - 1) + upper(n - 2);
    }
}

double lower(double n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    else
    {
        return lower(n - 1) + lower(n - 2);
    }
}
