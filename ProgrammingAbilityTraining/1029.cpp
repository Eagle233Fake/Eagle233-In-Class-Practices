#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    cin.ignore();

    unordered_set<string> s = {
        "a", "the", "an", "of", "for", "and"
    };

    for (int i = 0; i < T; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        int count = 0;

        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (s.find(word) == s.end()) {
                count++;
            }
        }

        cout << "case #" << i << ":" << endl << count << endl;
    }
}