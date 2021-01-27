#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#define LL long long

using namespace std;

const int MAX_N = 10005;
int n;
vector<int> vec[MAX_N]; //存图
int pre[MAX_N];         //存储前驱节点
bool visited[MAX_N];
bool root[MAX_N]; //是否有前驱结点
int u, v;       //求u，v的最近公共祖先
int node;       //记录结点u和v的最近公共祖先
int findset(int x)
{
    if (pre[x] != x)
        pre[x] = findset(pre[x]);
    return pre[x];
}
void unionset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if (x == y)
        return;
    pre[y] = x;
}
void LCA(int par)
{
    for (int i = 0; i < vec[par].size(); i++)
    {
        LCA(vec[par][i]);
        unionset(par, vec[par][i]);
    }
    visited[par] = true;
    if (par == u && visited[v] == true)
    {
        node = findset(v);
        return;
    }
    if (par == v && visited[u] == true)
    {
        node = findset(u);
        return;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < MAX_N; i++)
        {
            vec[i].clear();
            pre[i] = i;
            root[i] = true;
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n - 1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            vec[a].push_back(b);
            root[b] = false;
        }
        scanf("%d%d", &u, &v);
        int pos; //根节点位置
        for (int i = 1; i <= n - 1; i++)
            if (root[i] == true)
            {
                pos = i;
                break;
            }
        LCA(pos);
        cout << node << endl;
    }
    return 0;
}
