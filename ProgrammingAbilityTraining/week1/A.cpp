#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    string a, b;
    while (cin >> a >> b)
    {
        string s;
        reverse(a.begin(), a.end()); // 翻转字符串功能
        reverse(b.begin(), b.end());

        int length = max(a.length(), b.length());
        int carry = 0;
        for (int i = 0; i < length; i++)
        {
            int digit_a = i < a.length() ? a[i] - '0' : 0;
            int digit_b = i < b.length() ? b[i] - '0' : 0;
            int sum = digit_a + digit_b + carry;
            carry = sum / 10;
            sum %= 10;
            s.push_back(sum + '0');
        }

        if (carry)
        {
            s.push_back('1');
        }
        reverse(s.begin(), s.end());

        cout << s << endl;
    }
}