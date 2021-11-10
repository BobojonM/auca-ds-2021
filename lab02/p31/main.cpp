

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, mx = 0;
    vector<int> vc;
    while (cin >> n && n)
    {
        vc.push_back(n);
        mx = max(mx, n);
    }

    cout << "PERFECTION OUTPUT\n";

    for (int v : vc)
    {
        int sum = 0;
        for (int i = 1; i * i <= v; i++)
            if (v % i == 0)
            {
                sum += i;
                sum += (v / i != i && i != 1) ? (v / i) : 0;
            }

        cout << setw(to_string(mx).length()) << v << " ";
        if (sum == v)
            cout << "PERFECT\n";
        else if (sum < v)
            cout << "DEFICIENT\n";
        else
            cout << "ABUNDANT\n";
    }

    cout << "END OF OUTPUT\n";
}
