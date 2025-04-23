#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        getline(cin, s);
        cin.ignore();
        stringstream ss(s);

        vector<string> tokens;
        while (ss >> s) {
            tokens.push_back(s);
        }

        stack<double> st;

        for (int j = tokens.size() - 1; j >= 0; j--) {
            if (tokens[j] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push_back(tokens[j]);
            } else {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                if (tokens[j] == "+") {
                    st.push_back(a + b);
                }
                if (tokens[j] == "-") {
                    st.push_back(a - b);
                }
                if (tokens[j] == "*") {
                    st.push_back(a * b);
                }
                if (tokens[j] == "/") {
                    st.push_back(a / b);
                }
            }
        }

        double result = st.top();

        cout << "case #" << i << ":" << endl << fixed << setprecision(6) << result << endl;
    }
}