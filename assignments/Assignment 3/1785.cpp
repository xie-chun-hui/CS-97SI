#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 55555;
int dmax[MAX_N][20];
int mm[MAX_N];
int n;

struct node
{
    char v[150];
    int r;
    bool operator<(const node &b) const
    {
        return strcmp(v, b.v) < 0;
    }
} nodes[MAX_N];

int maxv(int i, int j)
{
    if (nodes[i].r > nodes[j].r)
        return i;
    return j;
}

void initMax()
{
    mm[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        dmax[i][0] = i;
        mm[i] = (i & (i - 1)) == 0 ? mm[i - 1] + 1 : mm[i - 1];
    }
    for (int j = 1; j <= mm[n]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            dmax[i][j] = maxv(dmax[i][j - 1], dmax[i + (1 << (j - 1))][j - 1]);
}

int getMax(int L, int R)
{
    int k = mm[R - L + 1];
    return maxv(dmax[L][k], dmax[R - (1 << k) + 1][k]);
}

void solve(int l, int r)
{
    if (l <= r)
    {
        int mid = getMax(l, r);
        printf("(");
        solve(l, mid - 1);
        printf("%s/%d", nodes[mid].v, nodes[mid].r);
        solve(mid + 1, r);
        printf(")");
    }
}

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", nodes[i].v);
            int j;
            for (j = 0; nodes[i].v[j] != '/'; j++)
                ;
            nodes[i].r = nodes[i].v[j] = 0;
            for (j++; nodes[i].v[j] != 0; j++)
                nodes[i].r = nodes[i].r * 10 + nodes[i].v[j] - '0';
        }
        sort(nodes + 1, nodes + n + 1);
        initMax();
        solve(1, n);
        printf("\n");
    }
    return 0;
}