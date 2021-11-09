#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    string line;
    cin >> t;
    getline(cin, line);
    while (t--)
    {
        getline(cin, line);
        if (count(line.begin(), line.end(), 'M') == count(line.begin(), line.end(), 'F'))
        {
            cout << "LOOP\n";
        }
        else
        {
            cout << "NO LOOP\n";
        }
    }
}
