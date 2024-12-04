#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = &array[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *arr[i]);
    }
    printf("\n");
}