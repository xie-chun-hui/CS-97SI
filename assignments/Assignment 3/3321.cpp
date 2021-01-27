#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;

int has[maxn];
int n;

struct Tree
{
    struct nod
    {
        int to, next;
    } edge[maxn];
    int in[maxn], out[maxn], tt;
    int head[maxn], ip;
    void init()
    {
        tt = 0, ip = 0;
        memset(head, -1, sizeof(head));
    }
    void add(int u, int v)
    {
        edge[ip].to = v;
        edge[ip].next = head[u];
        head[u] = ip++;
    }
    void dfs(int u)
    {
        in[u] = ++tt;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            dfs(v);
        }
        out[u] = tt;
    }
} G;

struct BIT
{
    int sum[maxn];
    void init()
    {
        memset(sum, 0, sizeof(sum));
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int pos, int x)
    {
        while (pos <= n)
        {
            sum[pos] += x;
            pos += lowbit(pos);
        }
    }
    int query(int pos)
    {
        int ans = 0;
        while (pos > 0)
        {
            ans += sum[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
} T;

int main()
{
    while (~scanf("%d", &n))
    {
        G.init();
        T.init();
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G.add(u, v);
        }
        G.dfs(1);
        for (int i = 1; i <= n; i++)
        {
            T.update(G.in[i], 1);
            has[i] = 1;
        }
        int x, m;
        scanf("%d", &m);
        char s[2];
        while (m--)
        {
            scanf("%s%d", s, &x);
            if (s[0] == 'C')
            {
                if (has[x])
                    T.update(G.in[x], -1);
                else
                    T.update(G.in[x], 1);
                has[x] ^= 1;
            }
            else
                printf("%d\n", T.query(G.out[x]) - T.query(G.in[x] - 1));
        }
    }
    return 0;
}