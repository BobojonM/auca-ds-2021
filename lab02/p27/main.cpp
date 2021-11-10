

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int d, k, res = 0;
        string names;
        cin >> d >> k >> names;

        vector<char> mp;
        for (int i = 0; i < d; i++)
        {
            if (i % k == 0 && !mp.empty())
                mp.erase(mp.begin());

            if (find(mp.begin(), mp.end(), names[i]) != mp.end())
            {
                res++;
            }
            mp.push_back(names[i]);
        }

        cout << "Case " << c << ": " << res << "\n";
    }
}
