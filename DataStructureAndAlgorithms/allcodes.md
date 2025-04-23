# All Codes of Data Structure and Algorithms Lab

## [Week 1](https://voj.mobi/contest/333) 20250221

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

## [Week 2](https://voj.mobi/contest/335) 20250228

### A 打印锯齿矩阵（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (v[i].size() == 0) {
            cout << " " << endl;
            continue;
        }

        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
```

### C 计算集合的并集（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return true;
        }
    }

    return false;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    for (int i = 0; i < m; i++) {
        if (search(v1, v2[i])) {
            continue;
        } else {
            v1.push_back(v2[i]);
        }
    }

    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
}
```

### D 小明学英语（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

bool search(vector<string> v, string target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int n;
    cin >> n;
    vector<string> v1;

    for (int i = 0; i < n; i++) {
        int status;
        cin >> status;
        if (status == 0) {
            string name;
            cin >> name;
            transform(name.begin(), name.end(), name.begin(), ::tolower); // 转为小写
            v1.push_back(name);
        } else {
            string name;
            cin >> name;
            transform(name.begin(), name.end(), name.begin(), ::tolower); 
            if (search(v1, name)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
```

### J islands 打炉石传说（二进制枚举）

```cpp
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
```

### Q 算法提高 选择排序

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool sorted = false;
    int index = 0;
    while (!sorted) {
        int a = v[index];
        int minNum = INT_MAX;
        int minIndex;
        for (int i = index; i < n; i++) {
            if (v[i] < minNum) {
                minNum = v[i];
                minIndex = i;
            }
        }
        if (minNum == a) {
            cout << "swap(a[" << index << "], a[" << index << "]):";
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            index++;
        } else {
            swap(v[index], v[minIndex]);
            cout << "swap(a[" << index << "], a[" << minIndex << "]):";
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            index++;
        }
        if (index == n) {
            sorted = true;
        }
    }
}
```

### R 得到整数 X

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[m] << endl;
}
```

## [Week 3](https://voj.mobi/contest/338) 20250308

### A 汉诺塔

```cpp
#include<iostream>
using namespace std;

long long moveCount(int n) {
    if (n == 1) {
        return 1;
    }
    return 1 + 2 * moveCount(n - 1);
}

long long strengthCost(int n) {
    if (n == 1) {
        return 1;
    }
    return n + 2 * strengthCost(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << moveCount(n) << " " << strengthCost(n);
    return 0;
}
```

### B 踏青

```cpp
#include<iostream>
using namespace std;

int px[4] = {-1, 1, 0, 0};
int py[4] = {0, 0, -1, 1};
char map[100][100];
int vst[100][100] = { 0 };
int n, m;

void grass(int x, int y) {
    vst[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + px[i];
        int ny = y + py[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && vst[nx][ny] == 0 && map[nx][ny] == '#') {
            grass(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '#' && vst[i][j] == 0) {
                grass(i, j);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
```

### C 金字塔数独

```cpp
#include<iostream>
using namespace std;

const int N = 9;
int grid[N][N];
int scores[N][N] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}
};
int maxScore = -1;

bool isValid(int x, int y, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[i][y] == num || grid[x][i] == num) {
            return false;
        }
    }

    int rowStart = 3 * (x / 3);
    int colStart = 3 * (y / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[rowStart + i][colStart + j] == num) {
                return false;
            }
        }
    }

    return true;
}

void solve(int x, int y, int totalScore) {
    if (x == N) {
        maxScore = max(maxScore, totalScore);
        return;
    }

    int nx = y == N - 1 ? x + 1 : x;
    int ny = y == N - 1 ? 0 : y + 1;
    if (grid[x][y] == 0) {
        for (int i = 1; i < 10; i++) {
            if (!isValid(x, y, i)) {
                continue;
            }
            grid[x][y] = i;
            solve(nx, ny, totalScore + i * scores[x][y]);
        }
        grid[x][y] = 0;
    }
    else {
        solve(nx, ny, totalScore + grid[x][y] * scores[x][y]);
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    solve(0, 0, 0);
    if (maxScore == 0) {
        cout << -1 << endl;
    }
    else {
        cout << maxScore << endl;
    }
    return 0;
}

```

### D 水果店（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<string, map<string, int>> m;
    for (int i = 0; i < n; i++) {
        string origin;
        string fruit;
        int sales;
        cin >> fruit >> origin >> sales;
        m[origin][fruit] += sales;
    }

    for (auto& p1 : m) {
        cout << p1.first << endl;
        for (auto& p2 : p1.second) {
            cout << "   |----" << p2.first << '(' << p2.second << ')' << endl;
        }
    }
}
```

### E 小明面试（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (m.find(a) != m.end()) {
            m[a]++;
        } else {
            m.insert({a, 1});
        }
    }

    int imax = INT_MIN;
    for (auto& [key, value] : m) { // 注意迭代器
        imax = max(value, imax);
    }

    int mmax = INT_MIN;
    for (auto& [key, value] : m) {
        if (value == imax) {
            mmax = max(mmax, key);
        }
    }
    cout << mmax << ' ' << imax << endl;
}
```

### F 网页跳转

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    stack<string> backStack, forwardStack;
    string current = "Ignore";
    for (int i = 0; i < n; i++) {
        string action;
        cin >> action;
        if (action == "VISIT") {
            string url;
            cin >> url;
            cout << url << endl;
            if (current != "Ignore") {
                backStack.push(current);
            }
            current = url;
            while (!forwardStack.empty()) {
                forwardStack.pop();
            }
        } else if (action == "BACK") {
            if (backStack.empty()) {
                cout << "Ignore" << endl;
            } else {
                forwardStack.push(current);
                current = backStack.top();
                backStack.pop();
                cout << current << endl;

            }
        } else if (action == "FORWARD") {
            if (forwardStack.empty()) {
                cout << "Ignore" << endl;
            } else {
                backStack.push(current);
                current = forwardStack.top();
                forwardStack.pop();
                cout << current << endl;
            }
        }
    }
}
```

### G 幼儿园买玩具（二进制枚举）

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    int result = 0;
    int list[101][16];
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> list[i][0];
        for (int j = 1; j <= list[i][0]; j++) {
            cin >> list[i][j];
        }
    }
    
    for (int i = 0; i < (1 << k); i++) {
        int flag[16] = {0};
        int count = 0;
        int num = 0;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                num++;
                flag[j + 1] = 1;
            }
        }
        for (int x = 0; x < n; x++) {
            bool a = true;
            for (int y = 1; y <= list[x][0]; y++) {
                if (flag[list[x][y]] == 0) {
                    a = false;
                }
            }
            if (a)
                count++;
        }
        if (count > result && num <= m) {
            result = count;
        }
    }
    
    cout << result;
    return 0;
}
```

### H 约瑟夫环问题（循环链表）

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    list<int> l;
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    auto it = l.begin();
    while (l.size() > 1) {
        for (int i = 1; i < m; i++) {
            it++;
            if (it == l.end()) {
                it = l.begin();
            }
        }

        cout << *it << " ";
        it = l.erase(it);
        if (it == l.end()) {
            it = l.begin();
        }
    }
    cout << *l.begin() << endl;
}
```

### I n个最小和（STL）

```cpp
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sum, i, j;
    bool operator>(const Node &other) const {
        return sum > other.sum;
    }
};

vector<int> kSmallestSums(vector<int> &A, vector<int> &B, int n) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    set<pair<int, int>> visited;
    
    minHeap.push({A[0] + B[0], 0, 0});
    visited.insert({0, 0});
    
    vector<int> result;
    
    while (n--) {
        Node cur = minHeap.top();
        minHeap.pop();
        result.push_back(cur.sum);

        int i = cur.i, j = cur.j;
        
        if (i + 1 < A.size() && !visited.count({i + 1, j})) {
            minHeap.push({A[i + 1] + B[j], i + 1, j});
            visited.insert({i + 1, j});
        }
        
        if (j + 1 < B.size() && !visited.count({i, j + 1})) {
            minHeap.push({A[i] + B[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    vector<int> result = kSmallestSums(A, B, n);

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
```

### J 字符串的冒泡排序

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSortTransform(string sh, const string &ch) {
    int n = sh.size();
    vector<int> steps;
    
    unordered_map<char, int> countSh, countCh;
    for (char c : sh) {
        countSh[c]++;
    }
    for (char c : ch) {
        countCh[c]++;
    }
    if (countSh != countCh) {
        return {-1};
    }

    for (int i = 0; i < n; i++) {
        if (sh[i] == ch[i]) {
            continue;
        }
        
        int pos = i;
        while (sh[pos] != ch[i]) pos++;

        for (int j = pos; j > i; j--) {
            swap(sh[j], sh[j - 1]);
            steps.push_back(j);
        }
    }

    steps.insert(steps.begin(), steps.size());
    return steps;
}

int main() {
    int n;
    string sh, ch;
    cin >> n >> sh >> ch;
    
    vector<int> result = bubbleSortTransform(sh, ch);
    
    if (result[0] == -1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
```

### K 插入排序

```cpp
#include <bits/stdc++.h>
#define MAXN 8010
using namespace std;

struct node {
    int val;
    int num;
    bool operator>(const node b) const {
        if (this->val != b.val) return this->val > b.val;
        return this->num > b.num;
    }
    bool operator<(const node b) const {
        if (this->val != b.val) return this->val < b.val;
        return this->num < b.num;
    }
};

node a[MAXN];
int n, q, type, x, v;
int order[MAXN];

void get_order() {
    for (int i = 1; i <= n; i++) {
        order[a[i].num] = i;
    }
}

void update(int x, int v) {
    a[order[x]].val = v;
    for (int i = order[x]; i < n; i++) {
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
        }
    }
    for (int i = order[x]; i > 1; i--) {
        if (a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
        }
    }
    get_order();
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].val);
        a[i].num = i;
    }
    sort(a + 1, a + n + 1);
    get_order();
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &x, &v);
            update(x, v);
        } else {
            scanf("%d", &x);
            printf("%d\n", order[x]);
        }
    }
    return 0;
}
```

## [Week 4](https://voj.mobi/contest/345) 20250315

