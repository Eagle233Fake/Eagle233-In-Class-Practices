#include <stdio.h>

int main(void)
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k)
                {
                    printf("   %d%d%d", i, j, k);
                    // %6d 占位6格
                }
            }
        }
    }
    printf("\n");
}