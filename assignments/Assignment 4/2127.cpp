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

int num1[501], num2[501];
int dp[501][501];
int path[501][501];

void print_path(int i, int j, int pre_pos, int &first)
{
    if (j == 0)
        return;
    print_path(i - 1, path[i][j], j, first);
    if (j != pre_pos)
    {
        if (first)
        {
            printf("%d", num2[j]);
            first = 0;
        }
        else
            printf(" %d", num2[j]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num1[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> num2[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        int pos = 0;
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j];
            path[i][j] = j;
            if (num1[i] > num2[j] && dp[i - 1][j] > dp[i - 1][pos])
                pos = j;
            if (num1[i] == num2[j])
            {
                dp[i][j] = dp[i - 1][pos] + 1;
                path[i][j] = pos;
            }
        }
    }
    int ans = 0;
    int x = 0;
    for (int i = 1; i <= M; i++)
    {
        if (ans < dp[N][i])
        {
            ans = dp[N][i];
            x = i;
        }
    }
    printf("%d\n", ans);
    int first = 1;
    print_path(N, x, 0, first);
    puts("");

    return 0;
}
