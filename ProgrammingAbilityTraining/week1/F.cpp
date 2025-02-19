#include <bits/stdc++.h>

using namespace std;

vector<double> f(26);

bool cmp(const char &a, const char &b) {
    char m = toupper(a);
    char n = toupper(b);
    if (m == n) {
        return a > b; // 1为a在前，0为b在前
    }

    int indexA = m - 'A';
    int indexB = n - 'A';
    if (f[indexA] == f[indexB]) {
        return m < n;
    }
    return f[indexA] > f[indexB];
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < 26; j++) {
            cin >> f[j];
        }

        string s;
        cin >> s;
        
        sort(s.begin(), s.end(), cmp);

        cout << s << endl;
    }
}