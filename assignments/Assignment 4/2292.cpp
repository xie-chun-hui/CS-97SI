#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 32;

char alph[] = " abcdefghijklmnopqrstuvwxyz+*/?";
int flect[140];
int num[N];
int s[N][N];
int dp[N][N];
int ans[N];

void init()
{
    for (int i = 1; i <= 30; i++)
        flect[(int)alph[i]] = i;
}
char str[N];

int main()
{
    init();
    int n, T, i, j, k;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for (i = 0; i < n; i++)
        {
            scanf("%s", str);
            for (j = 0; str[j]; j++)
                num[flect[(int)str[j]]]++;
        }
        //dp
        memset(dp, 0x3f, sizeof(dp));
        int sum = 0;
        for (i = 1; i <= 19; i++)
        {
            sum += num[i] * i;
            dp[1][i] = sum;
            s[1][i] = 1;
        }
        for (i = 2; i <= 12; i++)
            for (j = i; j <= 30; j++)
            {
                for (k = i; k <= j; k++)
                {
                    sum = 0;
                    for (int h = k; h <= j; h++)
                        sum += num[h] * (h - k + 1);
                    if (dp[i - 1][k - 1] + sum < dp[i][j])
                    {
                        dp[i][j] = dp[i - 1][k - 1] + sum;
                        s[i][j] = k;
                    }
                }
            }
        int cnt = 0;
        int now = 30;
        for (i = 12; i > 1; i--)
        {
            ans[cnt++] = s[i][now];
            now = s[i][now] - 1;
        }
        for (i = cnt - 1; i >= 0; i--)
            printf("%c", alph[ans[i]]);
        printf("\n");
    }
}