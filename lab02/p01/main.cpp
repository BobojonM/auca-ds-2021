#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int cycleLength(int x)
{
    int cnt = 1;
    while (x != 1)
    {
        cnt++;
        if (x % 2 == 1 && x != 1)
        {
            x = 3 * x + 1;
        }
        else
        {
            x = x / 2;
        }
    }
    return cnt;
}

int main()
{
    iostream::sync_with_stdio(false);

    int i, tmpi;
    int j, tmpj;
    while (cin >> i >> j)
    {
        tmpi = i;
        tmpj = j;
        if (j < i)
        {
            tmpi = j;
            tmpj = i;
        }
        int maxCycle = 0;

        for (int x = tmpi; x <= tmpj; x++)
        {
            int cycle = cycleLength(x);
            if (cycle > maxCycle)
            {
                maxCycle = cycle;
            }
        }
        cout << i << " " << j << " " << maxCycle << "\n";
    }
}