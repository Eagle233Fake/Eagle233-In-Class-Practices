#include <bits/stdc++.h>

using namespace std;

// 这个考试一定要带进去，根本做不来
string convert(int n, string s, int m) {
    // 将输入字符串从n进制转换为十进制
    vector<int> decimal_digits;
    for (char c : s) {
        int carry = c - '0';
        for (int &d : decimal_digits) {
            d = d * n + carry;
            carry = d / 10;
            d %= 10;
        }
        while (carry) {
            decimal_digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // 将十进制转换为m进制
    string result;
    vector<int> value(decimal_digits);
    do {
        int carry = 0;
        for (int i = value.size() - 1; i >= 0; --i) {
            carry = carry * 10 + value[i];
            value[i] = carry / m;
            carry %= m;
        }
        result.push_back('0' + carry);
        while (value.size() > 1 && value.back() == 0) {
            value.pop_back();
        }
    } while (!value.empty() && !(value.size() == 1 && value[0] == 0));

    reverse(result.begin(), result.end());
    return result;
}

int main(void) {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "case #" << i << ":" << endl;
        string s;
        cin >> s;
        string s2 = convert(10, s, 2);
        reverse(s2.begin(), s2.end());

        while (s2.size() > 1 && s2[0] == '0') {
            s2 = s2.substr(1);
        }

        string s3 = convert(2, s2, 10);
        cout << s3 << endl;
    }
}