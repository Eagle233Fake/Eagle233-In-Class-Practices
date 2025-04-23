#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }

        vector<int> dp(N + 1, 1);
        for (int i = 4; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 3];
        }

        cout << dp[N] << endl;
    }
}