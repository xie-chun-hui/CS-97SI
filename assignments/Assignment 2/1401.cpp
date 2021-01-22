#include <iostream>

using namespace ::std;

int Z(int n)
{
    int cnt = 0;
    while (n >= 5)
    {
        n /= 5;
        cnt += n;
    }
    return cnt;
}

int main()
{
    int nums;
    cin >> nums;
    while (nums--)
    {
        int n;
        cin >> n;
        cout << Z(n) << endl;
    }
    return 0;
}