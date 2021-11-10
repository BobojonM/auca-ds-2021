#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, r;
    cin >> t;
    while (t--)
    {
        cin >> r;
        vector<int> st(r);

        for (int i = 0; i < r; i++)
            cin >> st[i];

        unsigned int mn = 500 * 500 * 3000;
        for (int i = 0; i < r; i++)
        {
            unsigned int sum = 0;
            for (int j = 0; j < r; j++)
                if (i != j)
                    sum += abs(st[i] - st[j]);
            mn = min(mn, sum);
        }

        cout << mn << "\n";
    }
}
