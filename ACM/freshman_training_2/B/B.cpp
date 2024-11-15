#include <iostream>

using namespace std;

struct point
{
    char status;
    long long ways;
};

int main(void)
{
    int n, m;
    cin >> n >> m;

    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    point p[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p[i][j].status = s[i][j];
        }
    }

    p[0][0].ways = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[i][j].status == 'S' && p[i][j].status = '.')
            {
                p[i][j].ways = 
            }
        }
    }
}