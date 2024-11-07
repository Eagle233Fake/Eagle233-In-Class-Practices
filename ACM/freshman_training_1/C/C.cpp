#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    int number;
    int chinese;
    int math;
    int english;
    int score;
};

bool compare(student a, student b);

int main(void)
{
    int n;
    cin >> n;

    vector <student> stu(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].number = i + 1;
        stu[i].score = stu[i].chinese + stu[i].math + stu[i].english;
    }

    sort(stu.begin(), stu.end(), compare);

    for (int i = 0; i < 5 && i < n; i++)
    {
        cout << stu[i].number << " " << stu[i].score << endl;
    }

    return 0;
}

bool compare(student a, student b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else if (a.chinese != b.chinese)
    {
        return a.chinese > b.chinese;
    }
    else
    {
        return a.number < b.number;
    }
}