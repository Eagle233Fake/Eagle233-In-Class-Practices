#include <bits/stdc++.h>

using namespace std;

int cal(int &n, int amount) {
    int a = n / amount;
    n %= amount;
    return a;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << "case #" << i << ":" << endl;
        cout << cal(n, 100) << " " 
            << cal(n, 50) << " " 
            << cal(n, 20) << " " 
            << cal(n, 10) << " " 
            << cal(n, 5) << " " 
            << cal(n, 1) << endl;
    }
} 