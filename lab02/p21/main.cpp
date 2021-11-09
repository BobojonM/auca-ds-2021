#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int l, h, r, mx = 0, mn = 10001, t = 1;
    map<int, int> mp;
    while (cin >> l >> h >> r)
    {
        if (t)
        {
            t = 0;
            mn = l;
        }
        for (int i = l; i < r; i++)
            if (mp[i] < h)
                mp[i] = h;
        mx = max(mx, r);
    }

    cout << mn << " " << mp[mn];
    for (int i = mn + 1; i <= mx; i++)
    {
        if (mp[i] != mp[i - 1])
            cout << " " << i << " " << mp[i];
    }
    cout << "\n";
}
