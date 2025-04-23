#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        string line;
        getline(cin, line);

        for (int j = 0; j < line.size(); j++) {
            if (!isalnum(line[j])) {
                line[j] = ' ';
            }
        }
        stringstream ss(line);

        string s;
        set<string> dic;
        while (ss >> s) {
            dic.insert(s);
        }

        cout << "case #" << i << ":" << endl;
        for (string sss : dic) {
            cout << sss << " ";
        }
        cout << endl;
    }
}