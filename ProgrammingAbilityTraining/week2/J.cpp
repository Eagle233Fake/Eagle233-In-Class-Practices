#include <bits/stdc++.h>

using namespace std;

bool isDecimal(string b) {
    // return a != floor(a); // floor 返回的是整数部分
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '.') {
            return true;
        }
    }
    return false;
}

int main(void) {
    string a;
    char *b;
    while (cin >> a) {
        double m = stod(a);
        if (isDecimal(a)) {
            b = (char *)&m;
            for (int i = 0; i < 8; i++) {
                printf("%02x ", (unsigned char)*b); // %02x 用于输出每个字节的十六进制表示
                b++;
            }
        } else {

            int c = (int)m;
            b = (char *)&c;
            for (int i = 0; i < 4; i++) {
                printf("%02x ", (unsigned char)*b);
                b++;
            }
        }

        cout << endl;
    }
}