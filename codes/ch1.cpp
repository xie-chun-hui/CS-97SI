#include <iostream>

using namespace ::std;

double pow(double a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    double t = pow(a, n / 2);
    return t * t * pow(a, n % 2);
}

double pow2(double a, int n)
{
    double ret = 1;
    while (n)
    {
        if (n % 2 == 1)
            ret *= a;
        a *= a;
        n /= 2;
    }
    return ret;
}

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcdExtended(int a,int b, int* x, int * y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;  
    *y = x1;
    return gcd;  
}

int findMinX(int num[], int rem[], int k)
{
    int x = 1;
    while (true)
    {
        int j;
        for (j = 0; j < k; j++)
            if (x % num[j] != rem[j])
                break;
        if (j == k)
            return x;
        x++;
    }
    return x;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if(m == 1)
        return 0;
    while (a > 1)
    { 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y;   
        y = x - q * y; 
        x = t; 
    }
    if (x < 0)
        x += m0; 
    return x; 
}

int CRT(int num[], int rem[], int k)
{
    long long prod = 1;
    for (int i = 0; i < k; i++)
    {
        prod *= num[i];
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        long long pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

int main()
{
    cout << pow(10, 2) << endl;
    cout << pow2(10, 2) << endl;
    int x, y, a = 35, b = 15;  
    cout << gcdExtended(a, b, &x, &y) << endl;
    cout << modInverse(3, 11) << endl;
    int num[] = {3, 4, 5}; 
    int rem[] = {2, 3, 1}; 
    int k = sizeof(num)/sizeof(num[0]); 
    cout << CRT(num, rem, k)<< endl; 
    return 0; 
}