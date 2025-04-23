#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> dp(21, 0);
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;

    // 头部加0: dp[i - 1]
    // 头部加1: dp[i - 1] - (dp[i - 2] - dp[i - 3])
    for (int i = 4; i <= 20; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - 2] + dp[i - 3];
    }
    int n;

    while (cin >> n) {
        if (n == -1) {
            break;
        }
        cout << dp[n] << endl;
    }
}