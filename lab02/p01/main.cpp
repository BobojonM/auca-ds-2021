#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

long long int cycleLength(long long int x)
{
    long long int cnt = 1;
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

    long long i;
    long long j;
    while (cin >> i >> j)
    {
        long long int maxCycle = 0;
        for (long long int x = i; x <= j; x++)
        {
            long long int cycle = cycleLength(x);
            if (cycle > maxCycle)
            {
                maxCycle = cycle;
            }
        }
        cout << i << " " << j << " " << maxCycle << "\n";
    }
}