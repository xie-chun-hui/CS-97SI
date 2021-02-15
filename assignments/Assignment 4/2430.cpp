#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, K, b, cnt, f[5][1005][1005];
struct Node
{
    int sta, pos;
} node[1005];
bool cmp(Node a, Node b)
{
    return a.pos < b.pos;
}
int main()
{
    scanf("%d%d%d", &n, &K, &b);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &node[i].sta, &node[i].pos);
    sort(node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (node[i].pos == node[i - 1].pos)
            node[cnt].sta = 3;
        else
            node[++cnt] = node[i];
    }
    node[0].pos = node[1].pos;
    memset(f, 0x3f, sizeof(f));
    f[1][0][1] = f[2][0][1] = 1, f[3][0][1] = f[4][0][2] = 2;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            for (int k = K; k; k--)
            {
                if (node[j].sta == 1)
                {
                    int temp = min(f[1][j - 1][k - 1], min(f[2][j - 1][k - 1], min(f[3][j - 1][k - 1], f[4][j - 1][k - 1])));
                    f[1][j][k] = min(temp + 1, f[1][j - 1][k] + node[j].pos - node[j - 1].pos);
                    f[1][j][k] = min(f[1][j][k], f[4][j - 1][k] + node[j].pos - node[j - 1].pos);
                    f[3][j][k] = min(temp + 2, f[3][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos));
                    f[4][j][k] = f[4][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos);
                    f[4][j][k] = min(f[4][j][k], f[1][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                    f[4][j][k] = min(f[4][j][k], f[2][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                }
                else if (node[j].sta == 2)
                {
                    int temp = min(f[1][j - 1][k - 1], min(f[2][j - 1][k - 1], min(f[3][j - 1][k - 1], f[4][j - 1][k - 1])));
                    f[2][j][k] = min(temp + 1, f[2][j - 1][k] + node[j].pos - node[j - 1].pos);
                    f[2][j][k] = min(f[2][j][k], f[4][j - 1][k] + node[j].pos - node[j - 1].pos);
                    f[3][j][k] = min(temp + 2, f[3][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos));
                    f[4][j][k] = f[4][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos);
                    f[4][j][k] = min(f[4][j][k], f[1][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                    f[4][j][k] = min(f[4][j][k], f[2][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                }
                else
                {
                    int temp = min(f[1][j - 1][k - 1], min(f[2][j - 1][k - 1], min(f[3][j - 1][k - 1], f[4][j - 1][k - 1])));
                    f[3][j][k] = min(temp + 2, f[3][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos));
                    if (k > 1)
                        f[4][j][k] = min(f[1][j - 1][k - 2], min(f[2][j - 1][k - 2], min(f[3][j - 1][k - 2], f[4][j - 1][k - 2]))) + 2;
                    f[4][j][k] = min(f[4][j][k], f[4][j - 1][k] + 2 * (node[j].pos - node[j - 1].pos));
                    f[4][j][k] = min(f[4][j][k], f[1][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                    f[4][j][k] = min(f[4][j][k], f[2][j - 1][k - 1] + node[j].pos - node[j - 1].pos + 1);
                }
            }
        }
    }
    for (int i = 1; i <= 4; i++)
        f[1][cnt][K] = min(f[1][cnt][K], f[i][cnt][K]);
    printf("%d\n", f[1][cnt][K]);
}