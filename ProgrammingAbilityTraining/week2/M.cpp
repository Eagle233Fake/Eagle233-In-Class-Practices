#include <bits/stdc++.h>

using namespace std;

long long convert(string s) {
    vector<int> digit;
    unordered_map<char, int> m; // HashTable
    int base = 0;
    for (char c  : s) {
        if (m.find(c) == m.end()) {
            if (base == 0) {
                m[c] = 1;
            } else if (base == 1) {
                m[c] = 0;
            } else {
                m[c] = base;
            }
            base++;
        }
        digit.push_back(m[c]);
    }

    base = max(base, 2); // 不是一进制
    long long result = 0;
    for (int i : digit) {
        result = result * base + i;
    }
    return result;
}

int main(void) {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "case #" << i << ":" << endl;
        string a;
        cin >> a;
        cout << convert(a) << endl;
    }
}