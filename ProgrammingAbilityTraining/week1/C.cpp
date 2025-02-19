#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int prime[26];

bool cmp(const string& a, const string& b)
{
    int length = min(a.length(), b.length());
    for (int i = 0; i < length; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] - b[i] == 'a' - 'A')
            {
                return b[i] > a[i];
            }
            else if (b[i] - a[i] == 'a' - 'A')
            {
                return a[i] < b[i];
            }
            return prime[toupper(a[i]) - 'A'] < prime[toupper(b[i]) - 'A'];
        }
    }
    return a.length() < b.length();
}

int main(void)
{
    string s;
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            prime[s[i] - 'A'] = i;
        }

        getchar();

        string words;
        getline(cin, words); // 获取整行

        vector<string> v;

        int index = 0;
        for (int i = 0; i <= words.length(); i++)
        {
            if (i == words.length() || words[i] == ' ')
            {
                string word = words.substr(index, i - index);
                v.push_back(word);
                index = i + 1;
            }
        }

        sort(v.begin(), v.end(), cmp);
        for (string &word : v)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}