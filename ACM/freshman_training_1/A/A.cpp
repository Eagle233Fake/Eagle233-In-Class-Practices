#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(void)
{
    map <double, string> m;
    int n, k;
    cin >> n >> k;

    string number;
    double score;
    for (int i = 0; i < n; i++)
    {
        cin >> number >> score;

        m[score] = number;
    }

    auto p = m.end();
    advance(p, -k);
    cout << p->second << " " << p->first << endl;
}