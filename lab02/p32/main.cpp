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
        map<int, int> mp;

        for (int i = 1; i <= n; i++)
        {
            int j = i;
            while (j)
            {
                mp[j % 10]++;
                j /= 10;
            }
        }

        for (int i = 0; i <= 9; i++)
        {
            if (i > 0)
                cout << " ";
            cout << mp[i];
        }
        cout << "\n";
    }
}
