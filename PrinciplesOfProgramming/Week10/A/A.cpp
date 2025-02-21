#include <iostream>

using namespace std;

int main(void)
{
    int month, day;
    cin >> month >> day;

    if (month == 1 && day >= 1 && day <= 24)
    {
        cout << "Pig" << endl;
    }
    else
    {
        cout << "Mouse" << endl;
    }
}