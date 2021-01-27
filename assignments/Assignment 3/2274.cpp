#include <cstdio>
#include <queue>
#include <cmath>
#define mid ((l + r) / 2)
using namespace std;
struct CAR
{
    int x, v;
} car[250005];
const double eps = 1e-8;
int tree[5005];
int n, ans;
int pre[250005], nxt[250005];
struct heap
{
    double t, dis;
    int car1, car2;
    heap(double t, double dis, int car1, int car2) : t(t), dis(dis), car1(car1), car2(car2) {}
    bool operator<(heap x) const
    {
        if (fabs(t - x.t) < eps)
            return dis > x.dis;
        return t > x.t;
    }
};
void insert(int l, int r, int v, int k)
{
    if (l == r)
    {
        tree[k]++;
        return;
    }
    if (v <= mid)
        insert(l, mid, v, k * 2);
    else
        insert(mid + 1, r, v, k * 2 + 1);
    tree[k] = tree[k * 2] + tree[k * 2 + 1];
}
int ask(int l, int r, int k, int x, int y)
{
    if (x <= l && y >= r)
    {
        return tree[k];
    }
    int ans = 0;
    if (x <= mid)
        ans += ask(l, mid, k * 2, x, y);
    if (y > mid)
        ans += ask(mid + 1, r, k * 2 + 1, x, y);
    return ans;
}

priority_queue<heap> q;
int main()
{
    register int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        pre[i] = i - 1;
        nxt[i] = i + 1;
        scanf("%d %d", &car[i].x, &car[i].v);
        ans += ask(1, 100, 1, car[i].v + 1, 100);
        insert(1, 100, car[i].v, 1);
        ans %= 1000000;
    }
    printf("%d\n", ans);
    for (i = 1; i < n; i++)
    {
        if (car[i].v > car[i + 1].v)
        {
            double t = (car[i + 1].x - car[i].x) / (double)(car[i].v - car[i + 1].v);
            q.push(heap(t, (double)(car[i].x + (double)t * car[i].v), i, i + 1));
            heap hp = q.top();
        }
    }
    for (i = 1; i <= 10000 && !q.empty();)
    {
        heap hp = q.top();
        q.pop();
        if (nxt[hp.car1] != hp.car2 || pre[hp.car2] != hp.car1)
            continue;
        nxt[hp.car1] = nxt[hp.car2];
        pre[hp.car2] = pre[hp.car1];
        nxt[hp.car2] = hp.car1;
        pre[hp.car1] = hp.car2;
        nxt[pre[hp.car2]] = hp.car2;
        pre[nxt[hp.car1]] = hp.car1;
        if (nxt[hp.car1] <= n & car[hp.car1].v > car[nxt[hp.car1]].v)
        {
            double t = (double)(car[nxt[hp.car1]].x + car[nxt[hp.car1]].v * hp.t - hp.dis) / (car[hp.car1].v - car[nxt[hp.car1]].v);
            q.push(heap(hp.t + t, (double)(hp.dis + (double)car[hp.car1].v * t), hp.car1, nxt[hp.car1]));
        }
        if (pre[hp.car2] && car[pre[hp.car2]].v > car[hp.car2].v)
        {
            double t = (double)(hp.dis - car[pre[hp.car2]].v * hp.t - car[pre[hp.car2]].x) / (car[pre[hp.car2]].v - car[hp.car2].v);
            q.push(heap(hp.t + t, (double)(hp.dis + (double)car[hp.car2].v * t), pre[hp.car2], hp.car2));
        }
        printf("%d %d\n", hp.car1, hp.car2);
        i++;
    }
    return 0;
}