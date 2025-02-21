#include <iostream>

using namespace std;

int main(void)
{
    string s;
    getline(cin, s);

    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
        {
            s[i] = 'A' + (s[i] + 21 - 'A') % 26;
        }
    }
    cout << s;
}
