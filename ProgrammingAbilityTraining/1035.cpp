#include <bits/stdc++.h>

using namespace std;

void solve(void);

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":" << endl;
        solve();
    }
}

void solve(void) {
    int p, e, i, d;
    cin >> p >> e >> i >> d;

    int t = d + 1;
    while (true) {
        if ((t - p) % 23 == 0 &&
            (t - e) % 28 == 0 &&
            (t - i) % 33 == 0) {
            cout << "the next triple peak occurs in " << t - d << " days." << endl;
            return;
        }
        t++;
    }
    return;
}