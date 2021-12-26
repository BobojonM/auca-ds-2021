#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string line, cmd;
    getline(cin, line);
    stringstream s(line);
    vector<string> cmds;
    while (s >> cmd)
    {
        cmds.push_back(cmd);
    }

    int m;
    cin >> m;
    vector<vector<string>> data(m);
    for (int i = 0; i < m; i++)
    {
        vector<string> tmp(sz(cmds));
        for (int j = 0; j < sz(cmds); j++)
        {
            cin >> tmp[j];
        }
        data[i] = tmp;
    }

    int n;
    cin >> n;
    string sortCmd;
    for (int t = 0; t < n; t++)
    {
        if (t)
            cout << "\n";

        cin >> sortCmd;

        auto it = find(cmds.begin(), cmds.end(), sortCmd);
        int ind = it - cmds.begin();

        sort(data.begin(), data.end(), [ind](vector<string> a, vector<string> b)
             { return a[ind] < b[ind]; });

        for (int j = 0; j < sz(cmds); j++)
        {
            if (j)
                cout << " ";
            cout << cmds[j];
        }
        cout << "\n";

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < sz(cmds); j++)
            {
                if (j)
                    cout << " ";
                cout << data[i][j];
            }
            cout << "\n";
        }
    }
}
