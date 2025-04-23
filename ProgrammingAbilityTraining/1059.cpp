#include <bits/stdc++.h>

using namespace std;

bool isLegal(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 0) {
            return false;
        }
        if (i >= 3 && v[i] != v[i - 1] + v[i -2] + v[i - 3]) {
            return false;
        }

    }
    return true;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M;
        cin >> M;

        vector<int> v(M);
        for (int j = 0; j < M; j++) {
            cin >> v[j];
        }

        int index = -1;
        for (int j = 0; j < M; j++) {
            if (v[j] == -1) {
                index = j;
                if (j == 0) {
                    v[j] = v[3] - v[2] - v[1];
                } else if (j == 1) {
                    v[j] = v[3] - v[2] - v[0];
                } else if (j == 2) {
                    v[j] = v[3] - v[1] - v[0];
                } else {
                    v[j] = v[j - 1] + v[j - 2] + v[j - 3];
                }

                break;
            }
        }

        if (isLegal(v)) {
            cout << "case #" << i << ":" << endl << v[index] << endl;
        } else {
            cout << "case #" << i << ":" << endl << -1 << endl;
        }
    }
}