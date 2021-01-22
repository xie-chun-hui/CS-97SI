#include <iostream>
#include <vector>

using namespace ::std;

int main()
{
    int N;
    cin >> N;
    vector<int> num(N + 1, 0);
    vector<int> sum(N + 1, 0);
    vector<int> mod(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> num[i];
    for (int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + num[i];
        if (sum[i] % N == 0)
        {
            cout << i << endl;
            for (int j = 1; j <= i; j++)
                cout << num[j] << endl;
            break;
        }
        else if (mod[sum[i] % N] != 0)
        {
            cout << i - mod[sum[i] % N] << endl;
            for (int j = mod[sum[i] % N] + 1; j <= i; j++)
                cout << num[j] << endl;
            break;
        }
        mod[sum[i] % N] = i;
    }
    return 0;
}