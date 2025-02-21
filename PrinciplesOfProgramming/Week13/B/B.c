#include <stdio.h>

int main(void)
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("a[%d]=%d\n", i, *(&arr[i]));
    }
}