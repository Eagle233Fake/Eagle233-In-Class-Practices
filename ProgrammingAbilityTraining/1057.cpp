#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<vector<int>> tri;
        for (int i = 0; i < n; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
            tri.push_back(row);
        }

        for (vector<int> v: tri) {
            for (int i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}