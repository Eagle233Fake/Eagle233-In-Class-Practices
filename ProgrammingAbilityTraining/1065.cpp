#include <bits/stdc++.h>

using namespace std;

string mul(string a, string b) {
    const int L = 110;
    string s;
    int na[L], nb[L], nc[L];
    int La = a.size(), Lb = b.size();
    
    fill(na, na + L, 0);
    fill(nb, nb + L, 0);
    fill(nc, nc + L, 0);
    
    for (int i = La - 1; i >= 0; i--) 
        na[La - i] = a[i] - '0';
    
    for (int i = Lb - 1; i >= 0; i--) 
        nb[Lb - i] = b[i] - '0';
    
    for (int i = 1; i <= La; i++) {
        for (int j = 1; j <= Lb; j++) {
            nc[i + j - 1] += na[i] * nb[j];
        }
    }
    
    for (int i = 1; i <= La + Lb; i++) {
        nc[i + 1] += nc[i] / 10;
        nc[i] %= 10;
    }
    
    if (nc[La + Lb]) 
        s += nc[La + Lb] + '0';
    
    for (int i = La + Lb - 1; i >= 1; i--) 
        s += nc[i] + '0';
    
    while (s[0] == '0') 
        s = s.substr(1);  // 处理 a 或 b 为 0 的情况
    
    if (!s.size()) 
        s = "0";
    
    return s;
}

void solve(void) {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return;
    }

    string s = "2";
    string temp = s;
    for (int i = 0; i < n - 1; i++) {
        temp = mul(s, temp);
    }

    cout << temp << endl;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":" << endl;
        solve();
    }
}