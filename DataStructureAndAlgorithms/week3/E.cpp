#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (m.find(a) != m.end()) {
            m[a]++;
        } else {
            m.insert({a, 1});
        }
    }

    int imax = INT_MIN;
    for (auto& [key, value] : m) { // 注意迭代器
        imax = max(value, imax);
    }

    int mmax = INT_MIN;
    for (auto& [key, value] : m) {
        if (value == imax) {
            mmax = max(mmax, key);
        }
    }
    cout << mmax << ' ' << imax << endl;
}