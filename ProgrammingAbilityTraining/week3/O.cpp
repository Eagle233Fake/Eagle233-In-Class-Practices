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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int N, R;
        cin >> N >> R;

        string res = convert(N, R);
        cout << res << endl;
    }
}