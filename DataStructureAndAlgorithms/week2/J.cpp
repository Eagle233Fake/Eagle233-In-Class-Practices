#include <bits/stdc++.h>

using namespace std;

struct Card {
    int cost;
    bool d;
    int w;
};

int main(void) {
    int n;
    cin >> n;

    Card cards[n];
    for (int i = 0; i < n; i++) {
        cin >> cards[i].cost >> cards[i].d >> cards[i].w;
    }

    vector<int> dp(11, 0); // i点法力值时的最大攻击力
    for (int i = 0; i < n; i++) {
        if (!cards[i].d) {
            for (int j = 10; j >= cards[i].cost; j--) {
                dp[j] = max(dp[j], dp[j - cards[i].cost] + cards[i].w);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (cards[i].d) {
            for (int j = 10; j >= cards[i].cost; j--) {
                dp[j] = max(dp[j], dp[j - cards[i].cost] + cards[i].w);
            }
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < 11; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    cout << max << endl;
}