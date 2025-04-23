#include <bits/stdc++.h>

using namespace std;

string trans(string &s) {
    for (char &c : s) {
        if (isupper(c)) {
            c = 'A' + (((c - 'A') + 13) % 26);
        } else if (islower(c)) {
            c = 'a' + (((c - 'a') + 13) % 26);
        }
    }
    return s;
}

int main(void) {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        string word;
        string line;
        getline(cin, line);

        cout << "case #" << i << ":" << endl << trans(line) << endl;
    }
}