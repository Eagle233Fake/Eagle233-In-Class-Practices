#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        
        long double a = N;
        long double sum = 0;
        for (int j = 0; j < K; j++) {
            sum += a * a - M_PI * (a / 2) * (a / 2);
            a = a / sqrt(2);
        }

        cout << "case #" << i << ":" << endl << fixed << setprecision(6) << sum << endl;
    }
}