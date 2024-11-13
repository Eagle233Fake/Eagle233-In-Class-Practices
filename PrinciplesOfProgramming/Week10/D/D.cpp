#include <iostream>

using namespace std;

int main(void)
{
    string s;
    getline(cin, s);

    bool isNegative = false;
    if (s[0] == '-')
    {
        isNegative = true;
    }

    bool isFirst = true;

    if (s == "0")
    {
        cout << s;
    }
    else if (!isNegative)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                cout << s[i];
                break;
            }
            else if (s[i] == '0' && isFirst)
            {
                continue;
            }
            else
            {
                cout << s[i];
                isFirst = false;
            }
        }
    }
    else
    {
        cout << "-";
        for (int i = s.length() - 1; i >= 1; i--)
        {
            if (i == 0)
            {
                cout << s[i];
                break;
            }
            else if (s[i] == '0' && isFirst)
            {
                continue;
            }
            else
            {
                cout << s[i];
                isFirst = false;
            }
        }
    }
    cout << endl;
}