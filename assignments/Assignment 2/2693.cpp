#include <iostream>
#include <cmath>
#include <vector>
#define eps 0.0000000001
using namespace ::std;

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

struct Line
{
    double a, b, c;
};

int equal(double a, double b) { return fabs(a - b) < eps; }

Line bisector(Point p1, Point p2)
{
    Line line;
    if (equal(p1.x, p2.x))
    {
        line.a = 0.0;
        line.b = 1.0;
        line.c = -(p1.y + p2.y) / 2.0;
    }
    else if (equal(p1.y, p2.y))
    {
        line.a = 1.0;
        line.b = 0.0;
        line.c = -(p1.x + p2.x) / 2.0;
    }
    else
    {
        double k = -(p2.x - p1.x) / (p2.y - p1.y);
        double cx = (p1.x + p2.x) / 2.0;
        double cy = (p1.y + p2.y) / 2.0;
        double b = cy - k * cx;
        line.a = k, line.b = -1, line.c = b;
    }
    return line;
}

double Distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int count(vector<Point> &points, Point c)
{
    int res = 0;
    for (int i = 0; i < points.size(); i++)
    {
        double dis = Distance(points[i], c);
        if (dis > 2.5)
            continue;
        res++;
    }
    return res;
}

int main()
{
    vector<Point> points;
    double x, y;
    while (cin >> x >> y)
    {
        Point p(x, y);
        points.push_back(p);
    }
    int n = points.size();
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dis = Distance(points[i], points[j]);
            int tmp1, tmp2;
            if (dis > 5.0)
                continue;
            else if (equal(dis, 5.0))
            {
                Point c((points[i].x + points[j].x) / 2.0, (points[i].y + points[j].y) / 2.0);
                tmp1 = count(points, c);
            }
            else
            {
                Line line = bisector(points[i], points[j]);
                double d = sqrt(6.25 - (dis * dis) / 4.0);
                double em = sqrt(line.a * line.a + line.b * line.b);
                double ex = line.b / em;
                double ey = -line.a / em;
                double cx = (points[i].x + points[j].x) / 2.0;
                double cy = (points[i].y + points[j].y) / 2.0;
                Point c1(cx + d * ex, cy + d * ey);
                tmp1 = count(points, c1);
                Point c2(cx - d * ex, cx - d * ey);
                tmp2 = count(points, c2);
                tmp1 = tmp1 > tmp2 ? tmp1 : tmp2;
            }
            res = res < tmp1 ? tmp1 : res;
        }
    }
    cout << res << endl;
    return 0;
}