#include <bits/stdc++.h>

using namespace std;

unordered_map<string, char> wordToDigit = {
    {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'},
    {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
};

int wordToNumber(stringstream &ss) {
    string word;
    string numStr;
    while (ss >> word) {
        if (word == "+") {
            break;
        }
        if (word == "=") {
            break;
        }
        numStr += wordToDigit[word];
    }
    return stoi(numStr);
}

int main(void) {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        cout << "case #" << i << ":" << endl;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int A = wordToNumber(ss);
        int B = wordToNumber(ss);
        cout << A + B << endl;
    }
}