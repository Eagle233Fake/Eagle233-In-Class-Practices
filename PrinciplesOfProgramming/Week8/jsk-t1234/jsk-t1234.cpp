#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a;
    cin >> b;

    int m = a;
    for (int i = 0; i < b - 1; i++)
    {
        m = ((m % 7) * (a % 7)) % 7;
    }

    if (m == 1)
    {
        cout << "Monday" << endl;
    }
    else if (m == 2)
    {
        cout << "Tuesday" << endl;
    }
    else if (m == 3)
    {
        cout << "Wednesday" << endl;
    }
    else if (m == 4)
    {
        cout << "Thursday" << endl;
    }
    else if (m == 5)
    {
        cout << "Friday" << endl;
    }
    else if (m == 6)
    {
        cout << "Saturday" << endl;
    }
    else if (m == 0)
    {
        cout << "Sunday" << endl;
    }
}