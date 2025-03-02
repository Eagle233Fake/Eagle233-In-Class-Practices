#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (v[i].size() == 0) {
            cout << " " << endl;
            continue;
        }

        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}