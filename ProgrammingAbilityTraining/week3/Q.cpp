#include <bits/stdc++.h>

using namespace std;

vector<int> convert(string s) {
    vector<int> res;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            res.push_back(s[i] - '0');
            continue;
        } else {
            res.push_back(s[i] - 'A' + 10);
        }
    }
    return res;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string n, m;
        cin >> n >> m;

        reverse(n.begin(), n.end());
        reverse(m.begin(), m.end());

        vector<int> v1 = convert(n);
        vector<int> v2 = convert(m);

        int len = max(v1.size(), v2.size());
        vector<int> res(max(v1.size(), v2.size()) + 1, 0);
        for (int j = 0; j < len; j++) {
            int a = res[j];
            if (j < v1.size()) {
                a += v1[j];
            }
            if (j < v2.size()) {
                a += v2[j];
            }
            if (a >= 16) {
                res[j] = a - 16;
                res[j + 1]++;
            } else {
                res[j] = a;
            }
        }

        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        cout << "case #" << i << ":" << endl;
        for (int j : res) {
            if (j < 10) {
                cout << j;
            } else {
                cout << (char)(j - 10 + 'A');
            }
        }
        cout << endl;
    }
}