#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        vector<int> st(n);
        double sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
            sum += st[i];
        }

        double average = sum / n;
        int cnt = 0;

        for (int s : st)
            if (s > average)
                cnt++;

        cout << fixed << setprecision(3) << double(cnt * 100) / n << "%\n";
    }
}
