#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, n, i;
    double w, sum = 0, p = 0, an[105] = {0};
    scanf("%d%d%lf", &n, &v, &w);
    for (i = 0; i < n; i++) {
        scanf("%lf", &an[i]);
    }
    sort(an, an + n);
    for (i = 0; i < n; i++) {
        sum += an[i];
        if (sum / (i + 1) <= w) {
            p = sum / (i + 1);
        } else {
            break;
        }
    }
    if (i == 0)
        printf("0 0.00\n");
    else
        printf("%d %.2f\n", i * v, p / 100);
    return 0;
}
