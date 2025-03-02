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