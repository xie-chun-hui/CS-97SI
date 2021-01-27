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

const int MAX_N = 30001;

int root[MAX_N];
int cnt[MAX_N];
int up[MAX_N];

void init()
{
    for (int i = 0; i < MAX_N; i++)
    {
        root[i] = i;
        cnt[i] = 1;
        up[i] = 0;
    }
}

int Find(int x)
{
    if (root[x] != x)
    {
        int t = root[x];
        root[x] = Find(t);
        up[x] += up[t];
        return root[x];
    }
    return x;
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        root[b] = a;
        up[b] += cnt[a];
        cnt[a] += cnt[b];
    }
}

int main()
{
    int P;
    int a, b;
    scanf("%d", &P);
    init();
    for (int i = 0; i < P; i++)
    {
        char c[3];
        scanf("%s", c);
        if (c[0] == 'M')
        {
            scanf("%d%d", &a, &b);
            Union(a, b);
        }
        else
        {
            scanf("%d", &a);
            b = Find(a);
            printf("%d\n", cnt[b] - up[a] - 1);
        }
    }
    return 0;
}
