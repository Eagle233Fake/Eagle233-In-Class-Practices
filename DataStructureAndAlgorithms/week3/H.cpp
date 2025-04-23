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