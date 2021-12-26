#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

string to_lower(string a)
{
    for (int i = 0; i < sz(a); i++)
        a[i] = tolower(a[i]);

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int n;
        cin >> n;

        string name, value, tr;
        vector<pair<string, string>> vc;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
            name.pop_back();

            cin >> value >> tr;
            //cout << value << endl;

            string val = "";
            string cls;
            for (int j = 0; j < sz(value); j++)
            {
                if (value[j] == '-')
                {
                    if (cls == "upper")
                        val += "3";
                    else if (cls == "middle")
                        val += "2";
                    else
                        val += "1";
                    cls = "";
                    continue;
                }
                cls += value[j];
            }

            if (cls == "upper")
                val += "3";
            else if (cls == "middle")
                val += "2";
            else
                val += "1";

            reverse(begin(val), end(val));
            while (sz(val) < 10)
                val += "2";

            vc.emplace_back(val, name);
        }

        stable_sort(vc.begin(), vc.end(), [](pair<string, string> a, pair<string, string> b)
                    {
                        if (a.first == b.first)
                        {
                            return a.second < b.second;
                        }
                        return a.first > b.first;
                    });

        for (int i = 0; i < n; i++)
        {
            cout << vc[i].second << endl;
        }

        cout << "==============================\n";
    }
}
