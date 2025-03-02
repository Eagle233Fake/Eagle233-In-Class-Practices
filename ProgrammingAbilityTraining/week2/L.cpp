#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int index = s.find('.');
    if (index == -1) {
        index = s.length();
    }

    long long a = 0;
    // 计算整数部分
    long long power = 1;
    for (int i = index - 1; i >= 0; i--) {
        if (s[i] == '1') {
            a += power;
        } else if (s[i] == '2') {
            a -= power;
        }
        power *= 3;
    }

    // 计算小数部分
    long long b = 0, c = 1;
    for (int i = index + 1; i < s.length(); i++) {
        if (s[i] == '1') {
            b = b * 3 + 1;
            c *= 3;
        } else if (s[i] == '2') {
            b = b * 3 - 1;
            c *= 3;
        } else {
            b *= 3;
            c *= 3;
        }
    }

    // 带分数怎么计算：取决于符号位

    if (a > 0 && b < 0) {
        b = c + b;
        a -= 1;
    } else if (a < 0 && b > 0) {
        b = c - b;
        a += 1;
    }

    long long gcda = gcd(abs(b), c);
    b /= gcda;
    c /= gcda;

    if (index == s.length()) {
        cout << a << endl;
        return 0;
    }
    if (a == 0) {
        cout << b << " " << c << endl;
    } else {
        cout << a << " " << abs(b) << " " << c << endl;
    }
}