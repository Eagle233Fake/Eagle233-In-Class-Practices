#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <long long> v(n + 1);
    v[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        v[i] =  2 * v[i - 1] + 1;
    }

    vector <long long> h(n + 1);
    h[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        h[i] =  2 * h[i - 1] + i;
    }

    cout << v[n] << " " << h[n] << endl;

    return 0;
}