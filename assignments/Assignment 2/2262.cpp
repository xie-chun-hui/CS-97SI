#include <iostream>
#include <cmath>
#include <vector>

using namespace ::std;

#define MAX_N 1000000

vector<bool> primes(MAX_N, true);

void init()
{
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i < MAX_N; i++)
    {
        if (primes[i])
        {
            for (int j = 0; i * i + j * i < MAX_N; j++)
            {
                primes[i * i + j * i] = false;
            }
        }
    }
}

int main()
{
    init();
    while (true)
    {
        bool flag = false;
        int n;
        cin >> n;
        if (n == 0)
            break;
        int a, b;
        for (int i = 3; i <= n / 2; i++)
        {
            if (primes[i] && primes[n - i])
            {
                flag = true;
                a = i;
                b = n - i;
                break;
            }
        }
        if (flag)
            cout << n << " = " << a << " + " << b << endl;
        else
            cout << "Goldbach's conjecture is wrong." << endl;
    }
}