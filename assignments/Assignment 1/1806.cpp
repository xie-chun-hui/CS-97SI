#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

void draw(vvc &grid, int current)
{
    int petrol = grid.size();
    int center = petrol / 2;
    if (current == 1)
    {
        grid[center][center] = '0' + center;
        return;
    }
    for (int i = 0; i < grid.size() - 1; i++)
    {
        for (int j = 0; j < grid[i].size() - 1; j++)
        {
            int last = center + current - 2;
            if (grid[i][j] == '0' + last)
            {
                if (grid[i + 1][j] == '.')
                {
                    grid[i + 1][j] = '0' + (last + 1);
                }
                if (grid[i][j + 1] == '.')
                {
                    grid[i][j + 1] = '0' + (last + 1);
                }
                if (grid[i - 1][j] == '.')
                {
                    grid[i - 1][j] = '0' + (last + 1);
                }
                if (grid[i][j - 1] == '.')
                {
                    grid[i][j - 1] = '0' + (last + 1);
                }
            }
        }
    }
}

void print(vvc grid, int diff)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != '.')
            {
                int value = grid[i][j] - '0';
                grid[i][j] = (value - diff) + '0';
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int u;
        cin >> u;
        cout << "Scenario #" << i << ":" << endl;
        int m = 2 * u + 1;
        vvc grid(m);
        for (int k = 0; k < m; k++)
        {
            vc temp(m);
            for (int l = 0; l < m; l++)
            {
                temp[l] = '.';
            }
            grid[k] = temp;
        }
        vvvc slices;
        for (int j = 1; j <= m / 2 + 1; j++)
        {
            draw(grid, j);
            slices.push_back(grid);
        }
        for (int j = 0; j < slices.size() - 1; j++)
        {
            cout << "slice #" << j + 1 << ":" << endl;
            print(slices[j], j);
        }
        cout << "slice #" << slices.size() << ":" << endl;
        print(slices[slices.size() - 1], u);
        for (int j = slices.size() - 2; j >= 0; j--)
        {
            cout << "slice #" << 2 * slices.size() - j - 1 << ":" << endl;
            print(slices[j], j);
        }
        cout << endl;
    }
    return 0;
}
