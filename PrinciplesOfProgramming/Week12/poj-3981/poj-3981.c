// 做不来 本地能过voj过不了 放弃了

#include <stdio.h>
#include <string.h>

int main(void)
{
    char temp[10000];
    fgets(temp, strlen(temp), stdin);

    int len = strlen(temp);
    for (int i = 0; i < len; i++)
    {
        if (len - i >= 3 && 
            temp[i] == 'y' && temp[i + 1] == 'o' && 
            temp[i + 2] == 'u')
        {
            printf("we");
            i += 2;
        }

        else
        {
            printf("%c", temp[i]);
        }
    }

    if (temp[len - 1] == '\n') 
    {
        printf("\n");
    }
}