#include <bits/stdc++.h>

using namespace std;

struct KL {
    double value;
    int id;
};

bool cmp(const KL &a, const KL &b) {
    if (fabs(a.value - b.value) < 1e-7) {
        return a.id < b.id;
    }
    return a.value < b.value;
}

int main(void) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "case #" << i << ":" << endl;
        int k, n;
        cin >> k >> n;

        vector<vector <int>> v;
        for (int j = 0; j < n + 1; j++) {
            vector<int> temp;
            for (int c = 0; c < k; c++) {
                int tempNumber;
                cin >> tempNumber;
                temp.push_back(tempNumber);
            }

            v.push_back(temp);
        }

        vector<int> M(n + 1, 0);
        for (int j = 0; j < n + 1; j++) {
            for (int c = 0; c < k; c++) {
                M[j] += v[j][c];
            }
        }

        vector<vector <double>> p;
        for (int j = 0; j < n + 1; j++) {
            vector<double> temp;
            for (int c = 0; c < k; c++) {
                double tempNumber = (v[j][c] + (double)1.0 / k) / (M[j] + 1);
                temp.push_back(tempNumber);
            }

            p.push_back(temp);
        }

        vector<KL> kl;
        for (int j = 1; j < n + 1; j++) {
            double temp = 0;
            for (int c = 0; c < k; c++) {
                if (p[0][c] > 0 && p[j][c] > 0) {
                    temp += p[0][c] * log(p[0][c] / p[j][c]);
                }
            }
            if (fabs(temp) < 1e-7) {
                temp = 0.0000;
            }
            KL tempKL;
            tempKL.id = j;
            tempKL.value = temp;
            kl.push_back(tempKL);
        }

        sort(kl.begin(), kl.end(), cmp);

        for (KL tp : kl) {
            cout << tp.id << " " << fixed << setprecision(4) << tp.value << endl; // 回忆一下 setprecision
        }
    }
}