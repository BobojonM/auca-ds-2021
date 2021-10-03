#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int cycleLength(int x)
{
    int cnt = 0;
    while (x != 1)
    {
        if (x % 2 == 1 && x != 1)
        {
            cnt++;
            x = 3 * x + 1;
        }
        else
        {
            cnt++;
            x = x / 2;
        }
    }
    return cnt;
}

int main()
{
    iostream::sync_with_stdio(false);

    int i;
    int j;
    while (cin >> i >> j)
    {
        int maxCycle = 0;
        for (int x = i; x <= j; x++)
        {
            int cycle = cycleLength(x);
            if (cycle > maxCycle)
            {
                maxCycle = cycle;
            }
        }
        cout << i << " " << j << " " << maxCycle + 1 << "\n";
    }
}