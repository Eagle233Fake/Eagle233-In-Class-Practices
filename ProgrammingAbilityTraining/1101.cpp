#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, M;
        cin >> n >> M;

        vector<int> w(n + 1);
        vector<int> v(n + 1);

        vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }

        cout << dp[n][M] << endl;
    }
}