#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define maxn 40000 + 10
#define maxv 10000 + 10
struct node //存储输入的数据
{
    int u, v, length;
    char s;
} q[maxn];

struct question //存储询问
{
    int u, v, index, pos;

    friend bool operator<(question a, question b)
    {
        return a.index < b.index;
    }
} w[maxv];

struct gather //并查集
{
    int x, y, pre;
} g[maxn];
struct result //存储答案
{
    int ans, pos;
} e[maxv];
int n, m;

bool cmp(result a, result b)
{
    return a.pos < b.pos;
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        g[i].pre = i;
        g[i].x = g[i].y = 0;
    }
}

int Find(int x)
{
    int temp = g[x].pre;
    if (x == g[x].pre)
    {
        return x;
    }
    g[x].pre = Find(temp);
    g[x].x += g[temp].x;
    g[x].y += g[temp].y;
    return g[x].pre;
}

void join(int u, int v, int length, char s)
{
    int fx = Find(u), fy = Find(v);
    if (fx != fy)
    {
        g[fx].pre = fy;
        if (s == 'N')
        {
            g[fx].y = g[v].y + length - g[u].y, g[fx].x = g[v].x - g[u].x;
        }
        else if (s == 'S')
        {
            g[fx].y = g[v].y - length - g[u].y, g[fx].x = g[v].x - g[u].x;
        }
        else if (s == 'E')
        {
            g[fx].x = g[v].x + length - g[u].x, g[fx].y = g[v].y - g[u].y;
        }
        else
        {
            g[fx].x = g[v].x - length - g[u].x, g[fx].y = g[v].y - g[u].y;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    int i, k;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d %c", &q[i].u, &q[i].v, &q[i].length, &q[i].s);
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d%d%d", &w[i].u, &w[i].v, &w[i].index), w[i].pos = i;
    }
    sort(w, w + k);
    int ans, j = 0;
    for (i = 0; i < k; i++)
    {
        for (; j < w[i].index; j++)
        {
            join(q[j].u, q[j].v, q[j].length, q[j].s);
        }
        int u = w[i].u, v = w[i].v;
        int fx = Find(u), fy = Find(v);
        if (fx != fy)
        {
            ans = -1;
        }
        else
        {
            ans = abs(g[u].x - g[v].x) + abs(g[u].y - g[v].y);
        }
        e[i].ans = ans, e[i].pos = w[i].pos;
    }
    sort(e, e + k, cmp);
    for (int i = 0; i < k; ++i)
    {
        printf("%d\n", e[i].ans);
    }
    return 0;
}
