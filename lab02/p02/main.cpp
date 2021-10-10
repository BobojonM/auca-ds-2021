#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    double n, w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        double d2 = sqrt(1 + (8 * w));
        int x1 = (-1 + d2) / 2;
        cout << x1 << "\n";
    }
}