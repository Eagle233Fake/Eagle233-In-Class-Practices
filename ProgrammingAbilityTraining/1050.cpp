#include <bits/stdc++.h>

using namespace std;

int cal(int C, int W) {
    int mmax = pow(10, C);
    int mmin = pow(10, C - 1);
    int count = 0;
    for (int i = mmin + W; i < mmax; i += 10) {
        if (i % 3 == 0) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int C, W;
        cin >> C >> W;
        cout << "case #" << i << ":" << endl << cal(C, W) << endl;
    }
}