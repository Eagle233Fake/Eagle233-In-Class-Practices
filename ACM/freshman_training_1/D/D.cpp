#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct applicants
{
    int number;
    int score;
};

bool compare(const applicants &b, const applicants &c);

int main(void)
{
    int n, m;
    cin >> n >> m;
    int ac = static_cast <int> (m * 1.5);

    vector <applicants> a(n);

    for (auto &p : a)
    {
        cin >> p.number >> p.score;
    }

    sort(a.begin(), a.end(), compare);

    int real_ac = ac;

    for (int i = ac; i < n; i++)
    {
        if (a[i].score == a[ac - 1].score)
        {
            real_ac++;
        }
        else
        {
            break;
        }
    }

    cout << a[ac - 1].score << " " << real_ac << endl;

    for (int i = 0; i < real_ac; i++)
    {
        cout << a[i].number << " " << a[i].score << endl;
    }
}

bool compare(const applicants &b, const applicants &c)
{
    if (b.score != c.score)
    {
        return b.score > c.score;
    }
    else
    {
        return b.number < c.number;
    }
}