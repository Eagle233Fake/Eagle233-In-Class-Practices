#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int a = 0; a * a <= n; a++) { // 没什么好说的，暴力枚举
        for (int b = a; b * b <= n - a * a; b++) {
            for (int c = b; c * c <= n - a * a - b * b; c++) {
                double d = sqrt(n - a * a - b * b - c * c);
                if (!(d - (int)d)) {
                    cout << a << " " << b << " " << c << " " << (int)d << " " << endl;
                    return 0;
                }
            }
        }
    }
}