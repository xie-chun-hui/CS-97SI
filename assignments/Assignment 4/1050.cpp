#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int matrix[110][110];
int dp[110][110][110];

int main()
{
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int sums = 0;
                    for (int idx = i; idx <= j; idx++)
                        sums += matrix[k][idx];
                    if (dp[i][j][k - 1] >= 0)
                        dp[i][j][k] = dp[i][j][k - 1] + sums;
                    else
                        dp[i][j][k] = sums;
                    res = max(res, dp[i][j][k]);
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
