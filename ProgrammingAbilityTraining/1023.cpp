#include <bits/stdc++.h>

using namespace std;

int getNum(const string &s) {
    int sum = 0, flag = 0;
    for (char c : s) {
        if (isdigit(c)) {
            flag = 1;
            sum *= 10;
            sum += c - '0';
        }
    }

    if (flag == 0) {
        return -1;
    } else {
        return sum;
    }
}

bool strnumcmp(const string &a, const string &b) {
    int numA = getNum(a);
    int numB = getNum(b);
    if (numA == numB) {
        return a < b;
    }
    return numA < numB;

}

int main(void) {
    vector<string> v;

    string s;
    getline(cin ,s);
    stringstream ss(s);
    while (ss >> s) {
        v.push_back(s);
    }

    sort(v.begin(), v.end(), strnumcmp);

    for (string sss : v) {
        cout << sss << " ";
    }
    cout << endl;
}