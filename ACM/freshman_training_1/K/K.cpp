#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int m[t], n[t];
    for (int i = 0; i < t; i++)
    {
        cin >> m[i] >> n[i];
    }

    vector <vector <long long>> v(100001, vector <long long> (11, 1));
    for (int i = 1; i < 11; i++)
    {
        v[1][i] = 1;
        v[i][1] = 1;
    }


    for (int j = 2; j <= 100000; j++)
    {
        for (int k = 2; k <= 10; k++)
        {
            if (j - k >= 0)
            {
                v[j][k] = v[j][k - 1] + v[j - k][k];
            }
            else
            {
                v[j][k] = v[j][k - 1];
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << v[m[i]][n[i]] << endl;
    }
}