#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result.push_back(v1[i] + v2[j]);
        }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;
}