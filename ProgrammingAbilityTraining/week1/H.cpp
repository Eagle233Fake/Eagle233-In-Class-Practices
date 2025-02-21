#include <bits/stdc++.h>

using namespace std;

int times(string a) {
    vector<bool> t(26, false); // 注意初始化格式
    for (char s : a) {
        t[s - 'A'] = true;
    }

    int times = 0;
    for (int i = 0; i < 26; i++) {
        if (!t[i]) {
            times++;
        }
    }
    return times;
}

bool cmp(const string &a, const string &b) {
    int timesA = times(a);
    int timesB = times(b);

    if (timesA == timesB) {
        return a < b;
    }
    return timesA < timesB;
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "case #" << i << ":" << endl;
        int m;
        cin >> m;

        vector<string> v;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end(), cmp);
        for (string s : v) {
            cout << s << endl;
        }
    }
}