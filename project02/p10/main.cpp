#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, string>> cups;

    string color, value;
    int radius;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        if (isdigit(value[0]))
        {
            radius = stoi(value) / 2;
            cin >> color;
        }
        else
        {
            color = value;
            cin >> radius;
        }

        cups.emplace_back(radius, color);
    }

    sort(cups.begin(), cups.end());

    for (int i = 0; i < n; i++)
    {
        cout << cups[i].second << endl;
    }
}