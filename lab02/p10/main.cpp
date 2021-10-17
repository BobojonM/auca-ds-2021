#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, a;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> a;
        int preva = a, lj = 0, hj = 0;
        for (int j = 1; j < n; j++)
        {
            cin >> a;
            if (preva > a)
                lj++;
            else if (preva < a)
                hj++;
            preva = a;
        }
        cout << "Case " << i << ": " << hj << " " << lj << endl;
    }
}