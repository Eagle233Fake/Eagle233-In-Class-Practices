#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip> 

using namespace std;

struct Point
{
    double p;
    double t;
};

bool cmp(const Point& a, const Point& b);

int main(void)
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        cout << "case #" << i << ":" << endl;
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int j = 0; j < n; j++)
        {
            double x, y;
            cin >> x >> y;

            points[j].p = sqrt(x * x + y * y);

            points[j].t = atan2(y, x); // 计算弧度，返回范围是-pai到pai
            if (points[j].t < 0)
            {
                points[j].t += 2 * M_PI;
            }
        }

        sort(points.begin(), points.end(), cmp);

        for (const Point &p : points)
        {
            cout << fixed << setprecision(4); // 保留四位
            cout << "(" << p.p << "," << p.t << ")" << endl;
        }
    }
}

bool cmp(const Point& a, const Point& b)
{
    if (a.t == b.t)
    {
        return a.p > b.p;
    }
    return a.t < b.t;
}