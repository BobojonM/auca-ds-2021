#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int b, n;

    while (cin >> b >> n && (n != 0 || b != 0))
    {
        vector<int> vb(b);
        vector<int> vl(b);
        int d, c, v, t = 1;

        for (int i = 0; i < b; i++)
            cin >> vb[i];

        for (int i = 0; i < n; i++)
        {
            cin >> d >> c >> v;
            vb[c - 1] += v;
            vl[d - 1] += v;
        }

        for (int i = 0; i < b; i++)
        {
            if (vb[i] - vl[i] < 0)
            {
                cout << "N" << endl;
                t = 0;
                break;
            }
        }

        if (t)
            cout << "S" << endl;
    }
}