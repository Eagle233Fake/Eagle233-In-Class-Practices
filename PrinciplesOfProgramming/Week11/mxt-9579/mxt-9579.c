#include <stdio.h>

double calculate(int n, double x);

int main(void)
{
    int n;
    double x;
    scanf("%lf %d", &x, &n);
    if (n < 0)
    {
        printf("error\n");
        return 1;
    }

    printf("%.2lf\n", calculate(n, x));
}

double calculate(int n, double x)
{
    if (n == 0)
    {
        return 1;
    }

    else if (n == 1)
    {
        return 2.0 * x;
    }

    else
    {
        return 2.0 * x * calculate(n - 1, x) - 2.0 * (n - 1) * calculate(n - 2, x);
    }
}