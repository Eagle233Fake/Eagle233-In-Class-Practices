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