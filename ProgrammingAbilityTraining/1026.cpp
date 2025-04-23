#include <bits/stdc++.h>

using namespace std;

int eli(string &s) { // 双指针
    int count = 0;
    bool isEli = false;

    do {
        isEli = false;
       
        int i = 0;
        while (i < s.size()) {
            char c = s[i];
            int j = i;
            while (j < s.size() && s[j] == c) {
                j++;
            }
            if (j - i > 1) {
                count += j - i;
                s.erase(i, j - i);
                isEli = true;
            } else {
                i = j;
            }
            
        }
    } while (isEli && s.size() >= 1);

    return count;
}

int findMax(string &s) {
    vector<int> v;
    int mmax = 0;
    for (int i = 0; i <= s.size(); i++) {
        for (char ch : {'A', 'B', 'C'}) {
            string newStr = s;
            newStr.insert(i, 1, ch);
            mmax = max(mmax, eli(newStr));
        }
    }
    return mmax;
}

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        int count = findMax(s);

        cout << "case #" << i << ":" << endl << count << endl;
    }
}