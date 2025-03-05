#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        bitset<32> b(n);
        string b_str = b.to_string();
        reverse(b_str.begin(), b_str.end());
        b = bitset<32>(b_str);
        vector<int> dp(32, 1);
        int max = 1;
        bool start = false;
        for (int j = 0; j < 32; j++) {
            if (b[j] == 1 && !start) {
                start = true;
                continue;
            }
            if (start) {
                if (b[j] != b[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 1;
                }
                if (dp[j] > max) {
                    max = dp[j];
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        cout << max << endl;
    }
}