#include <stdio.h>

void swap(int arr[], int a, int b);

int main(void)
{
    int array[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    int test_1[10];
    int test_2[10];

    int select = 0;
    int sele = 0;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] % 2 == 1)
        {
            test_1[select] = array[i];
            select++;
        }
        else if (array[i] % 2 == 0)
        {
            test_2[sele] = array[i];
            sele++;
        }
    }

    int times = 0;
    int tem = 0;
    do
    {
        tem = times;
        for (int i = 0; i < select - 1; i++)
        {
            if (test_1[i] < test_1[i + 1])
            {
                swap(test_1, i, i + 1);
                times++;
            }
        }
    }
    while (tem != times);

    times = 0;
    tem = 0;
    do
    {
        tem = times;
        for (int i = 0; i < sele - 1; i++)
        {
            if (test_2[i] > test_2[i + 1])
            {
                swap(test_2, i, i + 1);
                times++;
            }
        }
    }
    while (tem != times);

    for (int i = 0; i < select; i++)
    {
        printf("%d ", test_1[i]);
    }
    for (int i = 0; i < sele; i++)
    {
        printf("%d ", test_2[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}