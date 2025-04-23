#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<long long> v;
        long long sum = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                v.push_back(i);
                if (i == n / i) {
                    continue;
                }
                v.push_back(n / i);
            }
        }

        for (int i : v) {
            sum += i * i;
        }

        cout << "case #" << i << ":" << endl << sum << endl;
    }
}