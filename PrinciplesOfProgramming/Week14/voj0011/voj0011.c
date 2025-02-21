#include <stdio.h>

int main(void)
{
    int m;
    scanf("%d", &m);
    int *arr = (int *)malloc(m * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }

    int avg = 0;
    for (int i = 0; i < m; i++)
    {
        avg += arr[i];
    }

    printf("%d ", avg);

    avg /= m;

    printf("%d\n", avg);

    free(arr);
}