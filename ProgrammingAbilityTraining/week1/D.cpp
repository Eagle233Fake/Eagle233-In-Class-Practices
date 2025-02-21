#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    int length = min(a.size(), b.size());
    for (int i = 0; i < length; i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return a.size() < b.size();
}

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        getchar();

        if (m == 1)
        {
            string s;
            getline(cin, s);
            int length = s.length();
            cout << s.substr(0, length - 3) << endl;
        }

        else
        {
            vector<vector<int>> v;
            for (int i = 0; i < m; i++)
            {
                string s;
                vector<int> temp;
                getline(cin, s);
                s = s.substr(0, s.length() - 3);

                int index = 0;
                for (int i = 0; i <= s.length(); i++)
                {
                    if (s[i] == ' ' || i == s.length())
                    {
                        temp.push_back(stoi(s.substr(index, i - index)));
                        index = i + 1;
                    }
                }

                v.push_back(temp);
            }
            sort(v.begin(), v.end(), cmp);
            for (const vector<int>& vec : v)
            {
                for (const int& v : vec)
                {
                    cout << v << " ";
                }
                cout << endl;
            }
        }
    }
}