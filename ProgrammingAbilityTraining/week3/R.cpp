#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;

        bitset<32> bx(x);
        bitset<32> by(y);
        int a = 0;
        for (int i = 0; i < 32; i++) {
            if (bx[i] != by[i]) {
                a++;
            }
        }

        cout << a << endl;
    }
}