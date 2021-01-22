#include <iostream>
#include <cmath>
#include <iomanip>

using namespace ::std;

# define PI 3.14159265358979323846

int main()
{
    int nums;
    cin >> nums;
    for (int i = 0; i < nums; i++)
    {
        float R, n;
        cin >> R >> n;
        cout << "Scenario #" << i + 1 << ":" << endl;
        cout << fixed << setprecision(3);
        cout << R * sin(PI / n) / (1 + sin(PI / n)) << endl << endl;
    }
    return 0;
}