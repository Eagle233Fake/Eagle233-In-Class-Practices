#include <bits/stdc++.h>

using namespace std;

bool isAo(int a) {
    string s;
    s = to_string(a);
    int i = 1;
    while (i < s.size() && s[i - 1] > s[i]) {
        i++;
    }
    if (i == 1 || i == s.size()) {
        return false;
    }
    while (i < s.size() && s[i - 1] < s[i]) {
        i++;
    }
    return i == s.size();
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        int cvt = 0;
        for (int j = a; j <= b; j++) {
            if (isAo(j)) {
                cvt++;
            }
        }
        cout << "case #" << i << ":" << endl << cvt << endl;
    }
}