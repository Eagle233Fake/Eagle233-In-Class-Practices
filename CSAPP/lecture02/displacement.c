#include <stdio.h>

int main(void)
{
    int i = 0x000000ff;
    printf("0x%x\n", i);
    i <<= 32;
    printf("0x%x\n", i);
    printf("%d\n", sizeof(int));
}