#include <stdio.h>

int main(void)
{
    int a, b;
    int *pa = &a;
    int *pb = &b;
    scanf("%d %d", &a, &b);

    printf("s=%d,t=%d\n", *pa + *pb, *pa * *pb);
}