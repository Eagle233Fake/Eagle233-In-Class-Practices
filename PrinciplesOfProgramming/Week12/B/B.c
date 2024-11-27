#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    char arr[10000] = {0};
    scanf("%s", arr);

    int array[26] = {0};

    int len = strlen(arr);
    char c;
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            c = arr[i];
        }
        else
        {
            c = arr[i - 1];    
        }
        if (c != arr[i])
        {
            array[arr[i] - 'a'] = 0;
        }
        array[arr[i] - 'a']++;
        if (array[arr[i] - 'a'] == n)
        {
            printf("%c", arr[i]);
            return 0;
        }
    }

    printf("No\n");
}