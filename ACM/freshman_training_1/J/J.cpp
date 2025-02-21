#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <vector <char>> room(n, vector <char> (n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> room[i][j];
        }
    }

    int days;
    cin >> days;

    for (int p = 0; p < days - 1; p++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (room[i][j] == '@')
                {
                    if (i - 1 >= 0 && room[i - 1][j] == '.')
                    {
                        room[i - 1][j] = '!';
                    }
                    if (i + 1 < n && room[i + 1][j] == '.')
                    {
                        room[i + 1][j] = '!';
                    }
                    if (j - 1 >= 0 && room[i][j - 1] == '.')
                    {
                        room[i][j - 1] = '!';
                    }
                    if (j + 1 < n && room[i][j + 1] == '.')
                    {
                        room[i][j + 1] = '!';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (room[i][j] == '!')
                {
                    room[i][j] = '@';
                }   
            }
        }
    }

    long long times = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (room[i][j] == '@')
            {
                times++;
            }
        }
    }

    cout << times;
}