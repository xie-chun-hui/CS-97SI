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

int main()
{
    ios::sync_with_stdio(false);
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<vector<int> > dp(2, vector<int>(n));
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (s[i] == s[j])
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
            else
                dp[i % 2][j] = min(dp[(i + 1) % 2][j], dp[i % 2][j - 1]) + 1;
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
