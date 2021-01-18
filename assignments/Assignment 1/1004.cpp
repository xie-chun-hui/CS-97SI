#include <iostream>

using namespace ::std;

int main()
{
    double total, balance;
    for (int i = 0; i < 12; i++)
    {
        cin >> balance;
        total += balance;
    }
    cout << "$" << total / 12 << endl;
    return 0;
}