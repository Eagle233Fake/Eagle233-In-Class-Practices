#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

int isEven(int n);

int main(void)
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 10, sizeof(int), cmp);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    int one = *((int *)a);
    int two = *((int *)b);

    if (isEven(one) && isEven(two))
    {
        return two - one;
    }

    else if ((!isEven(one)) && (!isEven(two)))
    {
        return one - two;
    }

    else if ((isEven(one)) && (!isEven(two)))
    {
        return -1;
    }

    else
    {
        return 1;
    }
}

int isEven(int n)
{
    if (n % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}