#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);

typedef struct good
{
    char id[7];
    char date[11];
    int price;
}good;

int main(void)
{
    int n;
    scanf("%d", &n);
    int m[n];
    good goods[200];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
        for (int j = 0; j < m[i]; j++)
        {
            scanf("%s %s %d", goods[index].id, goods[index].date, &goods[index].price);
            index++;
        }
    }
    
    int index3 = 0;
    for (int i = 0; i < n; i++)
    {
        qsort(goods + index3, m[i], sizeof(good), compare);
        index3 += m[i];
    }
    
    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        printf("case #%d:\n", i);
        for (int j = 0; j < m[i]; j++)
        {
            printf("%s %s %d\n", goods[index2].id, goods[index2].date, goods[index2].price);
            index2++;
        }
    }
}

int compare(const void *a, const void *b)
{
    good one = *(const good *)a;
    good two = *(const good *)b;

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