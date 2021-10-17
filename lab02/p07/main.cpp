#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b;

    while (cin >> a >> b && (a >= 0 && b >= 0))
    {
        cout << min(abs(b - a), (min(a, b) + 100 - max(a, b))) << endl;
    }
}