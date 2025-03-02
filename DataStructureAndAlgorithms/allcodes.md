# All Codes of Data Structure and Algorithms Lab

## Week 1 https://voj.mobi/contest/333

### A 两个整数a,b之和

```cpp
// 这题用C，CPP会超时
// https://blog.csdn.net/OOFFrankDura/article/details/79093578

#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }
}
```

### B 斐波那契数列

```cpp
#include <iostream>

using namespace std;

int num(int n);

int main(void) {
    int n;
    cin >> n;
    cout << num(n);
}

int num(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    
    int mod = 1000000007;
    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = (a + b) % mod;
        a = b;
        b = c;
    } // 防超时

    return c;
}
```

### C 矩阵旋转

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int v[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (j == n - 1) {
                cout << v[j][i];
                continue;
            }
            cout << " " << v[j][i];
        }
        cout << endl;
    }
}
```

### D 最大子阵

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            v[i][j] += v[i][j - 1];
        }
    }

    long long b[m];
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j == 0) {
                    b[k] = v[k][0];
                } else if (i != 0) {
                    b[k] = v[k][j] - v[k][i - 1];
                } else if (i == 0){
                    b[k] = v[k][j];
                }
            }

            vector<long long> dp(m, b[0]);
            long long mmax = dp[0];
            for (int k = 1; k < m; k++) {
                dp[k] = max(dp[k - 1] + b[k], b[k]);
                mmax = max(mmax, dp[k]);
            }

            ans = max(mmax, ans);
        }
    }

    cout << ans << endl;
}
```

### E 四平方和

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int a = 0; a * a <= n; a++) { // 没什么好说的，暴力枚举
        for (int b = a; b * b <= n - a * a; b++) {
            for (int c = b; c * c <= n - a * a - b * b; c++) {
                double d = sqrt(n - a * a - b * b - c * c);
                if (!(d - (int)d)) {
                    cout << a << " " << b << " " << c << " " << (int)d << " " << endl;
                    return 0;
                }
            }
        }
    }
}
```

### F A*B问题

```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> multi(vector<int> A, vector<int> B) {
    vector<int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    int t = 0;
    for (int i = 0; i < C.size(); i++) {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

int main(void) {
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }

    vector<int> C = multi(A, B);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
}
```

### G 得到整数 X

```cpp
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
```

## Week 2 https://voj.mobi/contest/335 20250228