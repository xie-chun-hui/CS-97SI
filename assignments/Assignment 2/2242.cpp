#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

#define PI 3.14159265358979323846

using namespace ::std;

double dis(vector<double> a, vector<double> b)
{
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

int main()
{
    vector<double> A(2);
    vector<double> B(2);
    vector<double> C(2);
    while (cin >> A[0] >> A[1] >> B[0] >> B[1] >> C[0] >> C[1])
    {
        double AB = dis(A, B), BC = dis(B, C), AC = dis(A, C);
        double cosA = (AB * AB + AC * AC - BC * BC) / (2 * AB * AC);
        double sinA = sqrt(1 - cosA * cosA);
        printf("%.2f\n", PI * (BC / sinA));
    }

    return 0;
}