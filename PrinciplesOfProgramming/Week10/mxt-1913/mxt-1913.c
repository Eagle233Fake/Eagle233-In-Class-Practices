#include <stdio.h>
#include <stdlib.h>

char *dex2Bin(int n);

int main(void)
{
    int a = 0, b = 0;
    for (int j = 1; j < 1001; j++)
    {
        int one = 0;
        int zero = 0;
        char *number_bin = dex2Bin(j);

        int k = 0;
        while (number_bin[k] != '\0')
        {
            if (number_bin[k] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }

            k++;
        }

        if (one > zero)
        {
            a++;
        }
        else
        {
            b++;
        }

        free(number_bin);
    }

    printf("%d %d", a, b);
}

char *dex2Bin(int n)
{
    int number_n = n;
    int i = 0;
    int length = 0;

    while (n > 0)
    {
        length++;
        n /= 2;
    }

    char *number = (char *)malloc(length + 1);

    while (number_n > 0)
    {
        if (number_n % 2 == 1)
        {
            number[i] = '1';
        }
        else
        {
            number[i] = '0';
        }
        number_n /= 2;
        i++;
    }
    number[i] = '\0';

    return number;
}