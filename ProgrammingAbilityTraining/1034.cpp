#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int count = 0;

        for (int k = 2; k < n; k++) {
            if (2 * n % k == 0) {
                if ((2 * n / k - k + 1) % 2 == 0 && (2 * n / k - k + 1) > 0) {
                    count++;
                }
            }
        }

        cout << "case #" << i << ":" << endl << count << endl;
    }
}