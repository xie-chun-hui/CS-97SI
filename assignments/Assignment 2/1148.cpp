#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
int a[10008];
int b[10008];
int sx[10008];
int sy[10008];
int jx[10008];
int jy[10008];

void dfs1(int l, int r, int n)
{
    if (n == 1)
    {
        jx[n] = a[l];
        return;
    }
    if (sx[n] == sx[n - 1])
    {
        jx[n] = a[l];
        dfs1(l + 1, r, n - 1);
    }
    else
    {
        jx[n] = a[r];
        dfs1(l, r - 1, n - 1);
    }
}
void dfs2(int l, int r, int n)
{
    if (n == 1)
    {
        jy[n] = b[l];
        return;
    }
    if (sy[n] == sy[n - 1])
    {
        jy[n] = b[l];
        dfs2(l + 1, r, n - 1);
    }
    else
    {
        jy[n] = b[r];
        dfs2(l, r - 1, n - 1);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == 4 || t == 1)
        {
            sx[i] = 1;
        }
        else
        {
            sx[i] = -1;
        }
        if (t == 1 || t == 2)
        {
            sy[i] = 1;
        }
        else
        {
            sy[i] = -1;
        }
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    if (sx[n] == -1)
    {
        for (int i = n; i >= 1; i = i - 2)
        {
            a[i] = -a[i];
        }
    }
    else
    {
        for (int i = n - 1; i >= 1; i = i - 2)
        {
            a[i] = -a[i];
        }
    }
    if (sy[n] == -1)
    {
        for (int i = n; i >= 1; i = i - 2)
        {
            b[i] = -b[i];
        }
    }
    else
    {
        for (int i = n - 1; i >= 1; i = i - 2)
        {
            b[i] = -b[i];
        }
    }
    dfs1(1, n, n);
    dfs2(1, n, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%+d %+d\n", jx[i], jy[i]);
    }
    return 0;
}