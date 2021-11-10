#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int l1 = s1.size(), l2 = s2.size();
        int sz = l1 + l2;
        int mn = sz;
        vector<int> vs1(sz);
        vector<int> vs2(sz);

        for (size_t i = 0; i < s1.size(); ++i)
            vs1[i] = s1[i] - '0';
        for (size_t i = 0; i < s2.size(); ++i)
            vs2[(sz - 1) - (s2.size() - 1 - i)] = s2[i] - '0';

        for (int i = 1; i <= sz; ++i)
        {
            int t = 1;
            for (int j = 0; j < i; ++j)
            {
                if (vs1[j] + vs2[sz - 1 - ((i - 1) - j)] > 3)
                {
                    t = 0;
                    break;
                }
            }

            if (t)
                mn = min(mn, l2 + ((i - l2) > 0 ? (i - l2) : 0) - ((i - l1) < 0 ? (i - l1) : 0));
        }

        cout << mn << "\n";
    }
}
