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

const int N = 2000002;

int root[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        root[i] = i;
    }
}

int find(int x)
{
    return root[x] == x ? x : root[x] = find(root[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    root[x] = y;
}

bool connect(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int T, N, M;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d%d", &N, &M);
        init(N * 2);
        char op[3];
        int a, b;
        for (int j = 0; j < M; j++)
        {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'A')
            {
                if (connect(a, b))
                    printf("In the same gang.\n");
                else if (connect(a, b + N))
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
            else
            {
                merge(a + N, b);
                merge(a, b + N);
            }
        }
    }
    return 0;
}