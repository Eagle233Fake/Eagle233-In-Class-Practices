#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, M;
        cin >> n >> M;
        
        vector<int> v(n + 1);
        vector<int> w(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> w[i] >> v[i];
        }

        vector<int> dp(M + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = M; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }

        cout << dp[M] << endl;
    }
}