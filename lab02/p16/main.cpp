#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;

    string text[] = {"Happy", "birthday", "to", "you", "Happy",
                     "birthday", "to", "you", "Happy", "birthday",
                     "to", "Rujia", "Happy", "birthday", "to", "you"};
    string names[n];

    for (int i = 0; i < n; i++)
        cin >> names[i];

    int ln = 16 * ceil((double)n / 16);
    for (int i = 0; i < ln; i++)
        cout << names[(i % 3)] << ": " << text[i % 16] << "\n";
}