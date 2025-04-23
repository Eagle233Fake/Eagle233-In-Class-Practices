#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

bool isRUN(int y) {
    if (y % 4 == 0 && y % 100 != 0) {
        return true;
    }
    return false;
}

void calBias(void) {
    m[2008] = 5;
    for (int i = 2009; i <= 2100; i++) {
        if (isRUN(i - 1)) {
            m[i] = (m[i - 1] + 366) % 7;
        } else {
            m[i] = (m[i - 1] + 365) % 7;
        }
    }
}

int main(void) {
    calBias();
    int y;
    while (cin >> y) {
        cout << " SU MO TU WE TH FR SA" << endl;
        for (int i = 0; i < m[y]; i++) {
            cout << "   ";
        }
        int bias = m[y];

        for (int i = 1; i < 29; i++) {
            if (i < 10) {
                cout << "  " << i;
            } else {
                cout << " " << i;
            }
            bias++;
            if (bias % 7 == 0) {
                cout << endl;
                bias = 0;
            }
        }

        if (isRUN(y)) {
            cout << " 29";
            bias++;
            if (bias % 7 == 0) {
                cout << endl;
                bias = 0;
            }
        }

        if (bias == 0) {
            cout << endl;
        } else {
            cout << endl << endl;
        }
    }
}