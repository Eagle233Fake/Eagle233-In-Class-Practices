#include <bits/stdc++.h>
#include <bitset>

using namespace std;

bool cmp(const long long &a, const long long &b) {
    bitset<120> binaryA(a); // 转为 binary
    bitset<120> binaryB(b);
    if (binaryA.count() == binaryB.count()) { // 方法 count() 统计1的个数
        return a < b;
    }
    return binaryA.count() > binaryB.count();
}

int main(void) {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cout << "case #" << i << ":" << endl;
        int m;
        cin >> m;

        vector<long long> v;
        for (int j = 0; j < m; j++) {
            long long num;
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end(), cmp);

        for (long long l : v) {
            cout << l << " ";
        }
        cout << endl;
    }
}