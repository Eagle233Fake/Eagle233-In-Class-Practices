#include <stdio.h>

int signed_high_prod(int x, int y) {
    return ((long long)x * (long long)y) >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int a = x >> 31;
    int b = y >> 31;
    return signed_high_prod(x, y) + a * y + x * b;
}

unsigned unsigned_high_prod2(unsigned x, unsigned y) {
    return ((unsigned long long)x * (unsigned long long)y) >> 32;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("signed_high_prod = %x\n", signed_high_prod(x, y));
    printf("unsigned_high_prod = %x\n", unsigned_high_prod(x, y));
    printf("unsigned_high_prod2 = %x\n", unsigned_high_prod2(x, y));
}