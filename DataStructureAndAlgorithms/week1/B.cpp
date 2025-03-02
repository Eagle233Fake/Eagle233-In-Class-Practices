#include <iostream>

using namespace std;

int num(int n);

int main(void) {
    int n;
    cin >> n;
    cout << num(n);
}

int num(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    
    int mod = 1000000007;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = (a + b) % mod;
        a = b;
        b = c;
    } // 防超时

    return c;
}