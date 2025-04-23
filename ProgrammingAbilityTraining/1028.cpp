#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; t++) {
        string f;
        cin >> f;
        cin.ignore();

        string line;
        getline(cin, line);

        transform(line.begin(), line.end(), line.begin(), ::tolower);
        transform(f.begin(), f.end(), f.begin(), ::tolower);

        for (int j = 0; j < line.size(); j++) {
            if (!isalnum(line[j])) {
                line[j] = ' ';
            }
        }

        int i = 0;
        int j = 0;
        int index;
        bool found = false;
        while (i < line.size()) {
            if (line[i] == f[j]) {
                if ((line[i - 1] == ' ') || i == 0) {
                    index = i;
                    while (i < line.size() && j < f.size()) {
                        j++;
                        i++;
                        found = true;
                        if (i >= line.size() || j >= f.size()) {
                            break;
                        }
                        if (line[i] != f[j]) {
                            j = 0;
                            i = index + f.size();
                            found = false;
                            break;
                        }
                    }
                }
            } else {
                i++;
                continue;
            }

            if (found == true) {
                if (j == f.size() && (i == line.size()) || line[i] == ' ') {
                    cout << "case #" << t << ":" << endl << index + 1 << endl;
                    break;
                } else {
                    found = false;
                }
            }
        }
        
        if (!found) {
            cout << "case #" << t << ":" << endl << "None" << endl;
        }
    }
}