#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector <int> v;

    int n;
    int times = 0;
    while (cin >> n && n != 0)
    {
        v.push_back(n);
        times++;
    }

    vector <long long> stairs(100, 0);
    // 又不开 long long？
    stairs[0] = 1;
    stairs[1] = 1;
    stairs[2] = 2;
    stairs[3] = 4;

    for (int i = 4; i < 100; i++)
    {
        stairs[i] = stairs[i - 1] + stairs[i - 2] + stairs[i - 3];
    }

    for (int i = 0; i < times; i++)
    {
        if (v[i] == 0)
        {
            continue;
        }
        cout << stairs[v[i]] << endl;
    }
}