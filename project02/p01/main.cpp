#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && (n || m))
    {
        vector<int> vc(n);

        for (int i = 0; i < n; i++)
            cin >> vc[i];

        sort(vc.begin(), vc.end(), [&](int a, int b)
             {
                 if (a % m == b % m)
                 {
                     if (a % 2 == 0 && b % 2 != 0)
                         return false;
                     if (a % 2 != 0 && b % 2 == 0)
                         return true;
                     if (a % 2 == 1 && b % 2 == 1)
                         return a > b;
                     if (a % 2 == 0 && b % 2 == 0)
                         return a < b;
                 }
                 return a % m < b % m;
             });

        for (int i = 0; i < n; i++)
            cout << vc[i] << "\n";
    }
}