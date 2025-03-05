#include <bits/stdc++.h>

using namespace std;

string convert(int n, int R) { // convert n to R
    string res;
    bool flag = false;
    if (n == 0) {
        return "0";
    } else if (n < 0) {
        flag = true;
        n = -n;
    }
    while (n) {
        int t = n % R;
        if (t < 10) {
            res += t + '0';
        } else {
            res += t - 10 + 'A';
        }
        n /= R;
    }

    if (flag) {
        res += "-";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        
        cout << "case #" << i << ":" << endl;
        string s1 = convert(N, 2);
        string s2 = convert(N, 16);
        cout << s1 << " " << s2 << endl;
    }
}