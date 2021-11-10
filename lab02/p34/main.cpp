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
        int cnt = 0;
        for (int i = n; i <= m; i++)
        {
            map<char, int> mp;
            string num = to_string(i);
            int t = 1;
            for (int j = 0; j < (int)num.length(); j++)
            {
                if (!mp[num[j]])
                    mp[num[j]]++;
                else
                {
                    t = 0;
                    break;
                }
            }

            if (t)
                cnt++;
        }
        cout << cnt << "\n";
    }
}
