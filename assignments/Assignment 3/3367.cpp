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

using namespace std;

const int MAX_N = 11000;

struct node
{
    int l, r;
    char c;
} nodes[MAX_N];

int cnt;
char s[MAX_N];

void init()
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        nodes[i].l = nodes[i].r = -1;
    }
    cnt = 0;
}

void print()
{
    string ans;
    queue<int> q;
    q.push(cnt - 1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans.push_back(nodes[t].c);
        if (nodes[t].l != -1)
            q.push(nodes[t].l);
        if (nodes[t].r != -1)
            q.push(nodes[t].r);
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

void solve()
{
    int len = strlen(s);
    stack<int> st;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            nodes[cnt].c = s[i];
            st.push(cnt);
            cnt++;
        }
        else
        {
            int r = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            nodes[cnt].l = l;
            nodes[cnt].r = r;
            nodes[cnt].c = s[i];
            st.push(cnt);
            cnt++;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", s);
        init();
        solve();
        print();
    }
    return 0;
}
