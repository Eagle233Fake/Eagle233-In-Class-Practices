#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char arr[256];
    fgets(arr, sizeof(arr), stdin);

    char *p = NULL;
    int digit_number = 0;
    int length = strlen(arr);
    for (int i = 0; i < length; i++)
    {
        p = &arr[i];
        if (isdigit(*p))
        {
            digit_number++;
        }
    }

    printf("%d\n", digit_number);
}