# 牢记

## 1067 计算n!右端0的个数(I)

```cpp
void solve(void) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }
    cout << count << endl;
}
```