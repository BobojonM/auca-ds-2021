#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void sortAndPrint(vector<string> vc, int mx)
{
    sort(vc.begin(), vc.end(), [](string a, string b)
         {
             reverse(a.begin(), a.end());
             reverse(b.begin(), b.end());
             return a < b;
         });

    for (int i = 0; i < sz(vc); i++)
    {
        cout << fixed << setw(mx) << vc[i] << endl;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    string word;
    vector<string> vc;
    int mx = 0;
    bool a = false;
    while (getline(cin, word))
    {

        if (word.empty())
        {
            if (a)
                cout << "\n";
            sortAndPrint(vc, mx);

            vc.clear();
            mx = 0;
            a = true;
            continue;
        }

        vc.push_back(word);
        mx = max(mx, sz(word));
    }
    if (a)
        cout << "\n";
    sortAndPrint(vc, mx);
}
