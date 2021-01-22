#include <iostream>
#include <cmath>
#define lowbit(x) (x & (-x))

using namespace ::std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        cout << k - lowbit(k) + 1 << " " << k + lowbit(k) - 1 << endl;
    }
    return 0;
}