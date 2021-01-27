#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace ::std;

int main()
{
    map<string, int> mp;
    string key;
    int total = 0;
    while (getline(cin, key))
    {
        mp[key]++;
        total++;
    }
    map<string, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << fixed << setprecision(4) << (double)it->second / total * 100 << endl;
    }
    return 0;
}