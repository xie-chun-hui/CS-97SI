#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace ::std;

int main()
{
    ios::sync_with_stdio(false);
    string num;
    while (cin >> num && num != "0")
    {
        int len = num.length();
        vector<int> dp(len);
        dp[0] = 1;
        for (int i = 1; i < len; i++)
        {
            if (num[i] != '0')
            {
                dp[i] += dp[i - 1];
            }
            if ((num[i] <= '6' && num[i - 1] == '2') || num[i - 1] == '1')
            {
                if (i >= 2)
                    dp[i] = dp[i] + dp[i - 2];
                else
                    dp[i]++;
            }
        }
        cout << dp[len - 1] << endl;
    }
    return 0;
}