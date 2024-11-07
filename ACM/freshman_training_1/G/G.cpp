#include <iostream>

using namespace std;

int main(void)
{
    int array[1000001] = {0, 1, 1};
    for (int i = 3; i < 1000001; i++)
    {
        array[i] = (array[i - 1] + array[i - 2]) % 1000;
    }

    int n;
    cin >> n;
    int test[n];
    for (int i = 0; i < n; i++)
    {
        cin >> test[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[test[i]] << endl;
    }
}