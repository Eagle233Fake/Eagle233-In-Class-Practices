#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char s[10001];
    scanf("%s", s);

    int length = strlen(s);

    long long result = 0;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(s[i]))
        {
            result = (result * 10 + s[i] - '0') % 100007;
        }
    }

    printf("%lld\n", result);
}