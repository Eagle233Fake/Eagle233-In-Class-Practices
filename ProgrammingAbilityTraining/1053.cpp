#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<unsigned long long> v(37);

    v[0] = 0;
    v[1] = 1;
    v[2] = 1;

    for (int i = 3; i < 37; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }

    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << "case #" << i << ":" << endl << v[n] << endl;
    }
}