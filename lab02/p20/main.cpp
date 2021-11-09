#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, cnt = 0;
    string name, gName;
    while (cin >> t)
    {
        if (cnt)
            cout << "\n";

        map<string, int> db;
        vector<string> names(t);

        for (int i = 0; i < t; i++)
            cin >> names[i];

        int sum, g, a = 0;
        for (int i = 0; i < t; i++)
        {
            cin >> name >> sum >> g;
            db[name] -= sum;

            if (g)
            {
                a = sum / g;
                db[name] += sum - (a * g);
            }

            for (int j = 0; j < g; j++)
            {
                cin >> gName;
                db[gName] += a;
            }
        }

        for (auto n : names)
            cout << n << " " << db[n] << "\n";

        cnt++;
    }
}
