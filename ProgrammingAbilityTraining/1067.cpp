#include <bits/stdc++.h>

using namespace std;

int count(int n) {
    int cvt = 0;
    while (n >= 5) {
        cvt += n / 5;
        n /= 5;
    }
    return cvt;
}

int main(void) {
    int T;
    cin >> T;
    int n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int cvt = count(n);
        cout << "case #" << i << ":" << endl << cvt << endl;
    }

}