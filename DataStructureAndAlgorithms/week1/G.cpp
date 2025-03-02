// 二进制枚举？
// 实际上也是动态规划
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= v[i]; j--) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[x];
}