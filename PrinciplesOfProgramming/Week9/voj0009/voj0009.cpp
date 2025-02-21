#include <iostream>

using namespace std;

int function(int n);

int main(void)
{
    int n;
    cin >> n;

    cout << function(n) << endl;
}

int function(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    if (n > 1)
    {
        return (n * function(n - 1));
    }
}