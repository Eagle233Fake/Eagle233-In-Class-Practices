#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    while (cin >> N) {
        if (N == 0) {
            continue;
        }
        double M = N * log10(N);
        double F = M - floor(M);
        int f = pow(10, F);
        cout << f << endl;
    }
}