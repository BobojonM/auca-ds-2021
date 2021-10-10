

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int t, n, m, k;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m >> k;
        map<int, int> mp;
        mp[min(n, min(m, k))]++;
        mp[max(n, max(m, k))]++;
        cout << "Case " << i << ": " << (mp[n] == 0 ? n : mp[m] == 0 ? m
                                                                     : k)
             << "\n";
    }
}