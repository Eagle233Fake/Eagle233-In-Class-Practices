#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cin.ignore();  // 清除换行符
    for (int i = 0; i < n; i++) {
        string a;
        getline(cin, a);

        int m = 0;
        int n = a.length() * 8;
        for (int h = 0; h < a.length(); h++) {
            int c = a[h];
            bitset<8> d(c);
            m += d.count();
        }

        int gcda = gcd(m, n); // 为什么要先提取出来？
        m /= gcda; // 最小公因数
        n /= gcda;
        cout << m << "/" << n << endl;
    }
}