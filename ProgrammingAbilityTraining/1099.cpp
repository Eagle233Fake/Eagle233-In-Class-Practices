#include <bits/stdc++.h>

using namespace std;

void solve(void) {
    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= M; i++) {
        for (int j = N; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[N];
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