#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int j = 0; j < N; j++) {
            cin >> v[j];
        }

        vector<int> result(N, 0);
        bool done = false;
        while (!done) {
            for (int k = 0; k < N; k++) {
                int count = 0;
                for (int l = k + 1; l < N; l++) {
                    if (v[l] < v[k]) {
                        count++;
                    }
                }
                result[k] = count;
            }
            if (v == result) {
                done = true;
            }
            v = result;
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < N; j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}