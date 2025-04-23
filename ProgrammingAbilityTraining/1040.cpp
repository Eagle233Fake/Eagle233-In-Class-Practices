#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] * b[n - 1 - i];
        }

        cout << "case #" << i << ":" << endl << sum << endl;
    }
}