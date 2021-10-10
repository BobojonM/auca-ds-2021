

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n, m;
    int c = 1;

    while (cin >> n >> m && (n or m))
    {
        int res = ceil((double)n / m);
        res--;
        if (res > 26 && res >= 0)
        {
            cout << "Case " << c << ": "
                 << "impossible"
                 << "\n";
        }
        else
        {
            cout << "Case " << c << ": " << res << "\n";
        }
        c++;
    }
}