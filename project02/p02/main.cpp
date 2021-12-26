#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string job;
    int salary;
};

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;
    string word;
    cin >> m >> n;

    vector<Skill> vc(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vc[i].job >> vc[i].salary;
    }

    sort(vc.begin(), vc.end(), [](Skill a, Skill b)
         { return a.job < b.job; });

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        while (cin >> word && word != ".")
        {
            auto it = lower_bound(vc.begin(), vc.end(), word, [](Skill a, string w)
                                  { return a.job < w; });

            if (it != vc.end())
            {
                if ((*it).job == word)
                    sum += (*it).salary;
            }
        }
        cout << sum << "\n";
    }
}