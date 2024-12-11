#include <stdio.h>
#include <stdlib.h>

int arrMin(int **arr, int r, int c);

int main(void)
{
    int r, c;
    scanf("%d %d", &r, &c);

    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", arrMin(arr, r, c));

    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int arrMin(int **arr, int r, int c)
{
    int max[r];
    for (int i = 0; i < r; i++)
    {
        max[i] = arr[i][0];
        for (int j = 0; j < c; j++)
        {
            if (max[i] < arr[i][j])
            {
                max[i] = arr[i][j];
            }
        }
    }

    int min = max[0];
    for (int i = 1; i < r; i++)
    {
        if (min > max[i])
        {
            min = max[i];
        }
    }
    return min;
}