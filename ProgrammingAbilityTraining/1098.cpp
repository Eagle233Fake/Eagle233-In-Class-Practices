#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> L(m + 1, 0);
    vector<int> R(m + 1, 0);
    vector<long long> W(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        cin >> L[i] >> R[i] >> W[i];
    }

    vector<long long> dp(k + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
        int length = R[i] - L[i] + 1;
        for (int j = length; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - length] + W[i]);
        }

        for (int j = k + 1; j <= k + length; j++) {
            dp[k] = min(dp[k], dp[j - length] + W[i]);
        }
    }

    if (dp[k] == LLONG_MAX) {
        cout << -1;
    } else {
        cout << dp[k];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ':' << endl;
        solve();
        cout << endl;
    }
}