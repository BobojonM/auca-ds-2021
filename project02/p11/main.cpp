#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

string to_lower(string a)
{
    for (int i = 0; i < sz(a); i++)
        a[i] = tolower(a[i]);

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    int n, m;
    bool a = false;
    while (cin >> n >> m && !(n == 0 || m == 0))
    {
        if (a)
            cout << "\n";

        vector<string> vc(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        vector<string> vs(m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vs[i] += vc[j][i];
            }
        }

        stable_sort(vs.begin(), vs.end(), [](string sa, string sb)
                    { return to_lower(sa) < to_lower(sb); });

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << vs[j][i];
            }
            cout << "\n";
        }

        a = true;
    }
}
