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
        double j = 0;
        double s = 1;
        while (s <= w)
        {
            j++;
            s = ((1 + j) / 2) * j;
        }
        cout << j - 1 << "\n";
    }
}