

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string ns;
    while (cin >> ns && ns[0] - '0')
    {
        int n = stoi(ns);
        vector<int> vc(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> vc[i];
            mp[vc[i]] = i;
        }

        int t = 1;
        for (int i = 0; i < n && t; i++)
            for (int j = i + 1; j < n && t; j++)
                if (mp[(vc[j] - vc[i]) + vc[j]] > j)
                    t = 0;

        cout << (t ? "yes" : "no") << "\n";
    }
}
