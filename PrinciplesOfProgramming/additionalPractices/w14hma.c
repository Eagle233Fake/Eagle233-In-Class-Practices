#include <stdio.h>

int num(int m, int n)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (m * 10 + i > n)
        {
            return sum;
        }

        else
        {
            if (judge(m * 10 + i) == 1)
            {
                sum += num(m * 10 + i, n) + 1;
            }
        }
        return sum;
    }
}