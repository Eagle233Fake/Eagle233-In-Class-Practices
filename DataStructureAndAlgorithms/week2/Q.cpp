#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool sorted = false;
    int index = 0;
    while (!sorted) {
        int a = v[index];
        int minNum = INT_MAX;
        int minIndex;
        for (int i = index; i < n; i++) {
            if (v[i] < minNum) {
                minNum = v[i];
                minIndex = i;
            }
        }
        if (minNum == a) {
            cout << "swap(a[" << index << "], a[" << index << "]):";
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            index++;
        } else {
            swap(v[index], v[minIndex]);
            cout << "swap(a[" << index << "], a[" << minIndex << "]):";
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            index++;
        }
        if (index == n) {
            sorted = true;
        }
    }
}