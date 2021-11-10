

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
        for (int i = 0; i < d - 1; i++)
        {
            if ((i + 1) % k == 0 && !mp.empty())
                mp.erase(mp.begin());
            mp.push_back(names[i]);

            if (find(mp.begin(), mp.end(), names[i + 1]) != mp.end())
            {
                res++;
            }
        }

        cout << "Case " << c << ": " << res << "\n";
    }
}
