#include <cstdio>
#include <cstring>
#define emax(a, b) ((a) < (b) ? (b) : (a))
using namespace std;
const int MAXN = 20005;
const int MAXE = 40005;
const int INF = 0x3f3f3f3f;
struct edge
{
    int v, next;
};
edge e[MAXE];
int head[MAXN], subTree[MAXN], dp[MAXN];
int T, k, n, maxw, maxu;
char inc;

inline void adde(int u, int v)
{
    e[k].v = v;
    e[k].next = head[u];
    head[u] = k++;
}

inline void read(int &x)
{
    x = 0;
    inc = getchar();
    while (inc < '0' || inc > '9')
    {
        inc = getchar();
    }
    while (inc >= '0' && inc <= '9')
    {
        x = (x << 3) + (x << 1) + (inc ^ 48);
        inc = getchar();
    }
}

void dfs(int u, int fa)
{
    subTree[u] = 1;
    for (int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
        subTree[u] += subTree[v];
        dp[u] = emax(dp[u], subTree[v]);
    }
    dp[u] = emax(dp[u], n - subTree[u]);
}

int main()
{
    read(T);
    while (T--)
    {
        read(n);
        memset(head, -1, sizeof(head));
        k = 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i <= n; i++)
        {
            int u, v;
            read(u);
            read(v);
            adde(u, v);
            adde(v, u);
        }
        dfs(1, 0);
        maxw = INF;
        maxu = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] < maxw)
            {
                maxu = i;
                maxw = dp[i];
            }
        }
        printf("%d %d\n", maxu, maxw);
    }
    return 0;
}
