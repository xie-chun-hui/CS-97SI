#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace ::std;

#define MAXINT 1000000

int main()
{
    ios::sync_with_stdio(false);
    int V, P;
    cin >> V >> P;
    vector<int> pos(V);
    for (int i = 0; i < V; i++)
    {
        cin >> pos[i];
    }
    vector<vector<int> > dp(P, vector<int>(V));
    vector<vector<int> > cost(V, vector<int>(V));
    int idx = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = i; j < V; j++)
        {
            idx = pos[(i + j) / 2];
            for (int k = i; k <= j; k++)
            {
                cost[i][j] = cost[i][j] + abs(pos[k] - idx);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        dp[0][i] = cost[0][i];
    }
    for (int i = 1; i < P; i++)
    {
        for (int j = i; j < V; j++)
        {
            dp[i][j] = MAXINT;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[k + 1][j]);
            }
        }
    }
    cout << dp[P - 1][V - 1] << endl;
    return 0;
}