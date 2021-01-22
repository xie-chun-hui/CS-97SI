#include <iostream>
#include <vector>
#include <queue>

using namespace ::std;

void bfs(int n)
{
    queue<long long> q;
    q.push(1);
    while (!q.empty())
    {
        long long x = q.front();
        q.pop();
        if (x % n == 0)
        {
            cout << x << endl;
            return;
        }
        q.push(x * 10);
        q.push(x * 10 + 1);
    }
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        bfs(n);
    }
    return 0;
}
