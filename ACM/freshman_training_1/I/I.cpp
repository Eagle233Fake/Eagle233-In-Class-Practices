#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector <long long> a(1000002);

    a[0] = 1;
    a[1] = 2;

    for (long long i = 2; i < 1000002; i++)
    {
        a[i] = (2 * a[i - 1] + a[i - 2]) % 32767;
    }

    long long n;
    cin >> n;
    long long b[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (long long i = 0; i < n; i++)
    {
        cout << a[b[i] - 1] % 32767 << endl;
    }
}