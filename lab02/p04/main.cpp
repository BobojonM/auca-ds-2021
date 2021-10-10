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
        double res = n * (567 / 9);
        res += 7492;
        res = res * (235 / 47);
        res -= 498;

        cout << (abs((int)res) % 100) / 10 << "\n";
    }
}