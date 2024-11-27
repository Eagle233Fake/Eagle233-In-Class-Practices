#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[1000000];
    scanf("%s", arr);

    int array[26] = {0};

    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        array[arr[i] - 'a']++;
    }

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (array[arr[i] - 'a'] == 1)
        {
            printf("%c\n", arr[i]);
            return 0;
        }
    }

    printf("no\n");
}