#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string tele;

    cin >> tele;
    
    int n;
    for (char c : tele)
    {
        n = c - '0' - 8;
        if (n >= 0)
        {
            cout << n;
        }
        else
        {
            cout << n + 10;
        }
    }
    cout << endl;
}