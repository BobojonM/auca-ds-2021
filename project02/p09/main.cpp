#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int x;
    cin >> x;

    for (int test = 1; test <= x; test++)
    {
        int n;
        cin >> n;
        vector<int> r, b;

        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            string value = "";
            for (int j = 0; j < sz(str); j++)
            {
                if (str[j] == 'R')
                {
                    r.push_back(stoi(value));
                    value = "";
                    continue;
                }
                else if (str[j] == 'B')
                {
                    b.push_back(stoi(value));
                    value = "";
                    continue;
                }
                value += str[j];
            }
        }

        sort(b.begin(), b.end(), greater<int>());
        sort(r.begin(), r.end(), greater<int>());

        vector<int> seg;
        for (int i = 0; i < min(sz(r), sz(b)); i++)
            seg.push_back(b[i] + r[i] - 2);

        cout << "Case #" << test << ": " << accumulate(seg.begin(), seg.end(), 0) << endl;
    }
}