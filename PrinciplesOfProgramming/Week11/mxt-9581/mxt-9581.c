#include <stdio.h>

double cal(double x, double n);

int main(void)
{
    double x, n;
    scanf("%lf %lf", &x, &n);

    printf("%.2lf", cal(x, n));
}

double cal(double x, double n)
{
    if (n == 1)
    {
        return x / (1 + x);
    }

    else
    {
        return x / (n + cal(x, n - 1));
    }
}