#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main(void)
{
    set <string> s;
    string text;
    getline(cin, text);
    stringstream ss(text);
    string word;
    while (ss >> word)
    {
        s.insert(word);
    }

    for (auto p = s.begin(); p != s.end(); p++)
    {
        cout << *p << endl;
    }
}