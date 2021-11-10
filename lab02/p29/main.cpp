

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    vector<vector<string>> ct;
    while (cin >> line && line[0] != '#')
    {
        vector<string> tr(5);
        if (line[0] != 'e')
        {
            size_t pos = 0;
            string bins = line;
            int i = 0;
            while ((pos = bins.find(",")) != string::npos)
            {
                tr[i] = bins.substr(0, pos);
                bins.erase(0, pos + 1);
                i++;
            }
            tr[i] = bins;
            sort(tr.begin(), tr.end());
            ct.push_back(tr);
        }
        else
        {
            int mni = 1, mn = 999999999;
            for (int i = 0; i < (int)ct.size(); i++)
            {
                long int d = 0;
                for (int j = 0; j < (int)ct.size(); j++)
                    for (int k = 0; k < 5; k++)
                        if (ct[i][k] != ct[j][k])
                            d++;

                if (mn > d)
                {
                    mn = d;
                    mni = i + 1;
                }
            }

            cout << mni << "\n";
            ct.clear();
        }
    }
}
