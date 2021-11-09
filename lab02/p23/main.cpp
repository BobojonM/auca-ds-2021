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
        int sz = s1.size() + s2.size();
        vector<int> vs1(sz);
        vector<int> vs2(s2.size());
        for (size_t i = 0; i < s1.size(); ++i)
            vs1[i] = s1[i] - '0';
        for (size_t i = 0; i < s2.size(); ++i)
            vs2[i] = s2[i] - '0';

        for (size_t i = 0; i <= s1.size(); ++i)
        {
            int t = 1;
            for (size_t j = 0; j < s2.size(); ++j)
            {
                if (vs1[j + i] + vs2[j] > 3)
                {
                    t = 0;
                    break;
                }
            }

            if (t)
            {
                cout << max(s1.size(), i + (int)s2.size()) << endl;
                break;
            }
        }
    }
}
