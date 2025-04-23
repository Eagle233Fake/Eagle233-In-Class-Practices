#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    long long m;

    for (int i = 0; i < n; i++) {
        cin >> m;
        v[i] = m - i * k;
    }

    sort(v.begin(), v.end());

    long long b;
    if (n % 2 == 1) {
        b = v[n / 2];
    } else {
        b = (v[n / 2] + v[n / 2 - 1]) / 2;
    }

    if (b < 0) {
        b = 0;
    }

    long long sum = 0;
    for (long long i : v) {
        sum += abs(i - b);
    }

    cout << sum << endl;
}