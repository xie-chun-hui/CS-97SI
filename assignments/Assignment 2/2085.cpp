#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m && n != -1 && m != -1)
    {
        int i, j;
        int total = 0;
        for (i = n; i >= 1; i--)
        {
            total += n - i;
            if (total >= m)
                break;
        }
        for (j = 1; j < i; j++)
            cout << j << " ";
        int k = m + i - (n - i) * (n - i - 1) / 2;
        cout << k << " ";
        for (j = n; j >= i; j--)
        {
            if (j != k)
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}