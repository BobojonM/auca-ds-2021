#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        string line;
        getline(cin, line);

        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            for (int j = 0; j < (int)line.length(); j++)
            {
                if (line[j] != '.')
                    v.push_back(j);
            }
        }

        int res = 0;
        for (int i = 1; i < (int)v.size(); i += 2)
        {
            res += v[i] - v[i - 1];
        }

        cout << res << "\n";
    }
}
