#include <iostream>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << "*" << j << "=" << i * j << " ";
        }
        cout << endl;
    }
}