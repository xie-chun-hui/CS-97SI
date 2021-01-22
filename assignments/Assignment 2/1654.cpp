#include <iostream>
#include <cmath>
#include <string>
using namespace ::std;

long long dot[10][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
string step;

long long Area(long long x1, long long y1, long long x2, long long y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i != t; i++)
    {
        long long x1, x2, y1, y2;
        long long area = 0;

        cin >> step;

        x1 = dot[(int)step[0] - 48][0];
        y1 = dot[(int)step[0] - 48][1];
        if (step.length() != 1)
        {
            for (int j = 1; j != step.length() - 1; j++)
            {
                x2 = x1;
                y2 = y1;
                x1 += dot[(int)step[j] - 48][0];
                y1 += dot[(int)step[j] - 48][1];
                area += Area(x1, y1, x2, y2);
            }
        }
        area = (area > 0 ? area : (-area));
        if (area / 2 * 2 != area)
            cout << area / 2 << ".5" << endl;
        else
            cout << area / 2 << endl;
    }
    return 0;
}
