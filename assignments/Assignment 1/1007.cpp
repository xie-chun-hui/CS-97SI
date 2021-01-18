#include <iostream>
#include <vector>
#include <algorithm>

using namespace ::std;

struct DNA
{
    string s;
    int val;
};

bool cmp(DNA a, DNA b)
{
    return a.val < b.val;
}

int get(string d)
{
    int cnt[4] = {0};
    int res = 0;
    for (int i = 0; i < d.length(); i++)
    {
        switch (d[i])
        {
        case 'A':
            cnt[0]++;
            res += cnt[1] + cnt[2] + cnt[3];
            break;
        case 'C':
            cnt[1]++;
            res += cnt[2] + cnt[3];
            break;
        case 'G':
            cnt[2]++;
            res += cnt[3];
            break;
        case 'T':
            cnt[3]++;
            break;
        default:
            break;
        }
    }
    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<DNA> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].s;
        v[i].val = get(v[i].s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].s << endl;
    }
    return 0;
}
