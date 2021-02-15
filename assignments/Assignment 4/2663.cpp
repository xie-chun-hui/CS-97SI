#include <iostream>
#include <vector>
#include <algorithm>

using namespace ::std;

int main()
{
    int n;
    vector<int> dp(31);
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= 30; i += 2)
    {
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    }
    while (cin >> n && n != -1)
    {
        cout << dp[n] << endl;
    }
    return 0;
}