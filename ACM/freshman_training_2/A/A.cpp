#include <iostream>

using namespace std;

void hannuo(int n, char source, char auxiliary, char target, long long &moveCount, long long &heart);

int main(void)
{
    int n;
    cin >> n;

    long long moveCount = 0;
    long long heart = 0;
    hannuo(n, 'A', 'B', 'C', moveCount, heart);
    cout << moveCount << " " << heart << endl;

}

void hannuo(int n, char source, char auxiliary, char target, long long &moveCount, long long &heart)
{
    if (n == 1)
    {
        moveCount++;
        heart += n;
        return;
    }

    hannuo(n - 1, source, target, auxiliary, moveCount, heart);
    moveCount++;
    heart += n;
    hannuo(n - 1, auxiliary, source, target, moveCount, heart);
}
