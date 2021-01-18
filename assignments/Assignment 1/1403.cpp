#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>

using namespace std;

map<string, int> mp_name, mp_id;

char id_name[30][30], na_name[30][30];

struct node
{
    char Name[30], ID[30];
    bool operator<(node tmp) const
    {
        return (strcmp(Name, tmp.Name) <= 0);
    }
} res[30];

int n, cnt;
int ma[30], mb[30], match[30];
bool g[30][30], vis[30];
char tmp_str[120];

void input()
{
    mp_name.clear();
    mp_id.clear();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", id_name[i]);
        mp_id[id_name[i]] = i;
    }

    char op[2], str[30];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            g[i][j] = 1;
    }
    cnt = 0;
    while (scanf("%s", op) != EOF)
    {
        if (op[0] == 'Q')
            break;

        if (op[0] == 'E' || op[0] == 'L')
        {
            scanf("%s", str);
            if (mp_name.count(str) == 0)
            {
                strcpy(na_name[cnt], str);
                mp_name[str] = cnt++;
            }
            if (op[0] == 'E')
                vis[mp_name[str]] = 1;
            else
                vis[mp_name[str]] = 0;
        }
        else
        {
            scanf("%s", str);
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                    g[i][mp_id[str]] = 0;
            }
        }
    }
}

int path(int u)
{
    for (int v = 0; v < n; v++)
    {
        if (g[u][v] && !vis[v])
        {
            vis[v] = 1;
            if (ma[v] == -1 || path(ma[v]))
            {
                ma[v] = u;
                mb[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    memset(match, 0xff, sizeof(match));
    int cnt1 = 0, cnt2;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            if (g[x][y] == 0)
                continue;
            cnt1 = 0;
            cnt2 = 0;
            memset(ma, 0xff, sizeof(ma));
            memset(mb, 0xff, sizeof(mb));
            for (int i = 0; i < n; i++)
            {
                if (mb[i] == -1)
                {
                    memset(vis, 0, sizeof(vis));
                    cnt1 += path(i);
                }
            }
            memset(ma, 0xff, sizeof(ma));
            memset(mb, 0xff, sizeof(mb));
            g[x][y] = 0;
            for (int i = 0; i < n; i++)
            {
                if (mb[i] == -1)
                {
                    memset(vis, 0, sizeof(vis));
                    cnt2 += path(i);
                }
            }
            g[x][y] = 1;
            if (cnt1 > cnt2)
            {
                match[x] = y;
                break;
            }
        }
    for (int i = 0; i < n; i++)
    {
        strcpy(res[i].Name, na_name[i]);
        if (match[i] != -1)
            strcpy(res[i].ID, id_name[match[i]]);
        else
            strcpy(res[i].ID, "???");
    }
    sort(res, res + n);
    for (int i = 0; i < n; i++)
        printf("%s:%s\n", res[i].Name, res[i].ID);
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        input();
        solve();
    }
    return 0;
}