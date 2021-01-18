#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace ::std;

int main()
{
    vector<int> cnt(26, 0);
    string s;
    for (int i = 0; i < 4; i++)
    {
        getline(cin, s);
        for (int j = 0; j < s.length(); j++)
        {
            if (isalpha(s[j]))
                cnt[s[j] - 'A']++;
        }
    }
    int max_num = *max_element(cnt.begin(), cnt.end());
    for (int i = max_num; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] >= i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < 26; i++)
        cout << (char)('A' + i) << " ";
    cout << endl;
    return 0;
}