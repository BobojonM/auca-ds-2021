#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int lk;
        string url;
        set<int> st;
        map<int, vector<string>> mp;
        for (int j = 0; j < 10; j++)
        {
            cin >> url >> lk;
            st.insert(lk);
            mp[lk].push_back(url);
        }
        cout << "Case #" << i << ":\n";
        for (auto e : mp[*st.rbegin()])
        {
            cout << e << "\n";
        }
    }
}