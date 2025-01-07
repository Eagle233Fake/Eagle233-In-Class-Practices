#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct good
{
    char id[29];
    char date[29];
    int price;
}good;

int cmp(const void *a, const void *b);

int main(void)
{
    int n;
    scanf("%d", &n);

    int index1 = 0;
    int m[n];
    good goods[2000];

    for (int i = 0; i < n; i++)
    {
        int j;
        scanf("%d", &j);

        m[i] = j;
        for (int k = index1; k < index1 + m[i]; k++)
        {
            scanf("%s %s %d", goods[k].id, goods[k].date, &goods[k].price);
        }
        index1 += m[i];    
    }

    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        qsort(goods + index2, m[i], sizeof(good), cmp);
        index2 += m[i];
    }

    int index3 = 0;
    for (int i = 0; i < n; i++)
    {
        printf("case #%d:\n", i);
        for (int j = index3; j < index3 + m[i]; j++)
        {
            printf("%s %s %d\n", goods[j].id, goods[j].date, goods[j].price);
        }
        index3 += m[i];
    }
}

int cmp(const void *a, const void *b)
{
    good one = *((good *)a);
    good two = *((good *)b);

    if (strcmp(one.date, two.date) == 0)
    {
        if (one.price == two.price)
        {
            return strcmp(one.id, two.id);
        }
        return one.price - two.price;
    }
    return strcmp(two.date, one.date);
}