#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    bool a = false;
    int n;
    while (cin >> n && n)
    {
        if (a)
            cout << "\n";
        string name;
        vector<string> vc(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        stable_sort(vc.begin(), vc.end(), [](string va, string vb)
                    {
                        va = va.substr(0, 2);
                        vb = vb.substr(0, 2);
                        return va < vb;
                    });

        for (int i = 0; i < n; i++)
        {
            cout << vc[i] << endl;
        }

        a = true;
    }
}
