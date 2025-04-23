#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        int x, y, z;
        vector<vector<int>> v;
        for (x = 0; x <= N; x++) {
            if ((K - N - 2 * x) >= 0 && (2 * N - K + x) >= 0) {
                vector<int> vv(3);
                vv[0] = x;
                vv[1] = (K - N - 2 * x);
                vv[2] = (2 * N - K + x);
                v.push_back(vv);
            }
        }
        cout << "case #" << i << ":" << endl;
        if (v.empty()) {
            cout << -1 << endl;
        } else {
            for (vector<int> a : v) {
                cout << a[0] << " " << a[1] << " " << a[2] << endl;
            }
        }
    }
}