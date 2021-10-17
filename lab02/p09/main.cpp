#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        int mn = 100, mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        cout << (mx - mn) * 2 << endl;
    }
}