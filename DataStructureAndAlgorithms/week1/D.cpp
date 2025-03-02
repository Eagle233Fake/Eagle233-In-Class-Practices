#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            v[i][j] += v[i][j - 1];
        }
    }

    long long b[m];
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j == 0) {
                    b[k] = v[k][0];
                } else if (i != 0) {
                    b[k] = v[k][j] - v[k][i - 1];
                } else if (i == 0){
                    b[k] = v[k][j];
                }
            }

            vector<long long> dp(m, b[0]);
            long long mmax = dp[0];
            for (int k = 1; k < m; k++) {
                dp[k] = max(dp[k - 1] + b[k], b[k]);
                mmax = max(mmax, dp[k]);
            }

            ans = max(mmax, ans);
        }
    }

    cout << ans << endl;
}