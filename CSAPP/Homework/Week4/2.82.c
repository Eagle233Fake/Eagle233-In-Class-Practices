#include <stdio.h>

int main(void) {
    int x = 0x0fffffaa;
    int y = 0x0ee82736;
    int left = ((x + y) << 4) + y - x;
    int right = 17 * y + 15 * x;
    printf("left = %d, right = %d", left, right);
}