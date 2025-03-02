#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i].push_back(i + 1);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            continue;
        }
        v[a - 1].insert(v[a - 1].end(), v[b - 1].begin(), v[b - 1].end()); // 注意插入用法
        v[b - 1].clear(); // 注意清除用法
    }

    for (int i = 0; i < n; i++) {
        if (v[i].size() == 0) {
            cout << endl;
            continue;
        }

        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}