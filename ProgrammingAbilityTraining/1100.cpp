#include <bits/stdc++.h>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i *= 2) {
            for (int j = i; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - i]) % 1000000000;
            }
        }

        cout << "case #" << t << ':' << endl << dp[n] << endl;
    }
}