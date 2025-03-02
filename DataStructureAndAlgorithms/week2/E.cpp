#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int index = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            continue;
        } else {
            index++;
        }
    }

    vector<int> v1(index, 0);
    vector<int> v2;

    int index2 = 0;
    v2.push_back(v[0]);
    v1[0] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            v1[index2]++;
        } else {
            index2++;
            v1[index2]++;
            v2.push_back(v[i]);
        }
    }

    int max = 0;
    for (int i = 0; i < index; i++) {
        if (v1[i] > max) {
            max = v1[i];
        }
    }

    for (int i = index - 1; i >= 0; i--) {
        if (max == v1[i]) {
            cout << v2[i] << " " << v1[i] << endl;
            break;
        }
    }
}