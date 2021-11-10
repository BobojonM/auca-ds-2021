#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m, cs = 1;
    while (cin >> n && n > 0)
    {
        vector<int> vn(n);
        for (int i = 0; i < n; i++)
            cin >> vn[i];

        cin >> m;
        vector<int> vm(m);
        for (int i = 0; i < m; i++)
            cin >> vm[i];

        cout << "Case " << cs << ":\n";
        for (int k = 0; k < m; k++)
        {
            int res = 999999999, a = 0, b = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i != j)
                    {
                        if (res > abs((vn[i] + vn[j]) - vm[k]))
                        {
                            res = abs((vn[i] + vn[j]) - vm[k]);
                            a = vn[i];
                            b = vn[j];
                        }
                    }

            cout << "Closest sum to " << vm[k] << " is " << a + b << ".\n";
        }
        cs++;
    }
}
