#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }

    cout << count << endl;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":" << endl;
        solve();
    }
}