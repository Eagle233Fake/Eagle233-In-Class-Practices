#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(void)
{
    multimap <int, string> m;
    int n;
    cin >> n;

    string name;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        m.insert({score, name});
    }

    for (auto p = prev(m.end()); p != m.begin(); p--)
    {
        cout << p->second << " " << p->first << endl;
    }
    cout << (m.begin())->second << " " << (m.begin())->first << endl;
}