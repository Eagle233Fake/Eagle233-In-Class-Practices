#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return true;
        }
    }

    return false;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    for (int i = 0; i < m; i++) {
        if (search(v1, v2[i])) {
            continue;
        } else {
            v1.push_back(v2[i]);
        }
    }

    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
}