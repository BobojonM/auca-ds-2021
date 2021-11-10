#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, r;
    cin >> t;
    while (t--)
    {
        cin >> r;
        vector<int> st(r);

        for (int i = 0; i < r; i++)
            cin >> st[i];

        sort(st.begin(), st.end());

        cout << st[ceil((double)r / 2) - 1] << "\n";
    }
}
