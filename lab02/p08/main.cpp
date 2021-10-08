#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    int cnt = 0;
    while (getline(cin, line))
    {
        int ln = line.length();
        for (int i = 0; i < ln; i++)
        {
            char ch = line[i];
            if (ch == '"')
            {
                if (cnt % 2 == 0)
                {
                    cout << "``";
                }
                else
                {
                    cout << "''";
                }
                cnt++;
            }
            else
            {
                cout << ch;
            }
        }
        cout << "\n";
    }
}