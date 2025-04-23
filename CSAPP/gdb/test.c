#include <stdio.h>

int fun(void) {
    printf("hello, world\n");
    return 0;
}

int main(void) {
    int a;
    int b;
    a = 11;
    b = 20;
    for (int i = 0; i < 8; i++) {
        a++;    
    }

    fun();
    printf("%d\n", 666);
}