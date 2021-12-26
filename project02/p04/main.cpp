#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string dna;
    int diff;
};

SpecialString make_SpecialString(string dna)
{
    SpecialString a;
    a.dna = dna;

    int diff = 0;

    for (int i = 0; i < sz(dna) - 1; i++)
    {
        for (int j = i + 1; j < sz(dna); j++)
        {
            if (dna[i] > dna[j])
                diff++;
        }
    }

    //cout << diff << endl;

    a.diff = diff;

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    int x;
    cin >> x;
    for (int test = 0; test < x; test++)
    {
        if (test)
            cout << "\n";

        int n, m;
        string dna;
        cin >> n >> m;

        vector<SpecialString> vc;

        for (int i = 0; i < m; i++)
        {
            cin >> dna;
            vc.push_back(make_SpecialString(dna));
        }

        stable_sort(vc.begin(), vc.end(), [](SpecialString a, SpecialString b)
                    { return a.diff < b.diff; });

        for (int i = 0; i < m; i++)
        {
            cout << vc[i].dna << "\n";
        }
    }
}