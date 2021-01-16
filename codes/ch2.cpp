#include <iostream>
#include <stack>
#include <queue>

using namespace ::std;

template <typename T>
void print_queue(T &q)
{
    while (!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

class UF
{
private:
    vector<int> L;

public:
    UF(int n) : L(n)
    {
        for (int i = 0; i < n; i++)
            L[i] = i;
    }
    int Find(int x)
    {
        return x == L[x] ? x : L[x] = Find(L[x]);
    }
    void Union(int x, int y)
    {
        int rootx = Find(x), rooty = Find(y);
        if (rootx == rooty)
            return;
        L[rootx] = rooty;
    }
};

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    priority_queue<int> p1;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        p1.push(n);
    print_queue(p1);
    priority_queue<int, vector<int>, greater<int>> p2;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        p2.push(n);
    print_queue(p2);
    return 0;
}