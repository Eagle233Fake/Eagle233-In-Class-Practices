#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":" << endl;
        int x, y;
        int N, M;
        cin >> N >> M;
        if ((M - 2 * N) % 2 != 0 || (4 * N - M) % 2 != 0 || (M - 2 * N) < 0 || (4 * N - M) < 0) {
            cout << "Impossible" << endl;
        } else {
            x = (M - 2 * N) / 2;
            y = (4 * N - M) / 2;
            cout << y << " " << x << endl;
        }
    }
}