#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    stack<string> backStack, forwardStack;
    string current = "Ignore";
    for (int i = 0; i < n; i++) {
        string action;
        cin >> action;
        if (action == "VISIT") {
            string url;
            cin >> url;
            cout << url << endl;
            if (current != "Ignore") {
                backStack.push(current);
            }
            current = url;
            while (!forwardStack.empty()) {
                forwardStack.pop();
            }
        } else if (action == "BACK") {
            if (backStack.empty()) {
                cout << "Ignore" << endl;
            } else {
                forwardStack.push(current);
                current = backStack.top();
                backStack.pop();
                cout << current << endl;

            }
        } else if (action == "FORWARD") {
            if (forwardStack.empty()) {
                cout << "Ignore" << endl;
            } else {
                backStack.push(current);
                current = forwardStack.top();
                forwardStack.pop();
                cout << current << endl;
            }
        }
    }
}