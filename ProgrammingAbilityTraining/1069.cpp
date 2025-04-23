#include <bits/stdc++.h>

using namespace std;

int rec(int A, int B, int C) {
    int r = A % C;
    B--;
    while (B > 0) {
        r = (r * A % C) % C;
        B--;
    }
    return r % C;
}

int main(void) {
    int A, B, C;
    while (cin >> A >> B >> C) {
        if (A == 0 && B == 0 && C == 0) {
            break;
        }

        cout << rec(A, B, C) << endl;
    }
}