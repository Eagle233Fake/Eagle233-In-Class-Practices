#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    vector <int> v(26);

    for (char c : s)
    {
        v[c - 'a']++;
    }

    int max = 0;
    for (auto p = v.begin(); p != v.end(); p++)
    {
        if (*p > max)
        {
            max = *p;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (v[i] == max)
        {
            char b = 'a' + i;
            cout << b << " " << v[i];
            return 0;
        }
    }
}