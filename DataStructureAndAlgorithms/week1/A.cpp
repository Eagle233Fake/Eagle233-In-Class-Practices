// 这题用C，CPP会超时
// https://blog.csdn.net/OOFFrankDura/article/details/79093578

#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }
}