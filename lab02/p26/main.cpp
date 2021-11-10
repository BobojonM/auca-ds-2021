

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;
    while (cin >> n && n > 0)
    {
        cin >> m;
        vector<int> vn(n);
        for (int i = 0; i < n; i++)
            cin >> vn[i];

        vector<int> vm(m);
        for (int i = 0; i < m; i++)
            cin >> vm[i];

        vector<double> d;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                d.push_back((double)vm[j] / vn[i]);

        double res = 0;
        for (size_t i = 0; i < d.size() - 1; i++)
            res = max(res, d[i + 1] / d[i]);

        cout << fixed << setprecision(2) << res << "\n";
    }
}
