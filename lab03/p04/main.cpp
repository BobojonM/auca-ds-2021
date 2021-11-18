#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void eliminate(int n, vector<string> names, vector<vector<int>> votes);

int main()
{
    string line;
    int tests, n, v;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        cin >> n;

        vector<string> names(n);
        vector<vector<int>> votes;

        cin.ignore();

        for (int i = 0; i < n; i++)
            getline(cin, names[i]);

        while (getline(cin, line) && !line.empty())
        {
            istringstream sinp(line);
            vector<int> tmp(n);
            for (int i = 0; sinp >> v; i++)
                tmp[i] = v - 1;
            votes.push_back(tmp);
        }

        if (test)
            cout << endl;
        eliminate(n, names, votes);
    }
}

int winner(vector<vector<int>> votes, vector<int> &eliminates, vector<int> &candidates, vector<string> names, int &mn, int &mx)
{
    int all = 0, n = sz(names);

    for (int i = 0; i < sz(votes); i++)
        for (int j = 0; j < n; j++)
            if (!eliminates[votes[i][j]])
            {
                all++;
                candidates[votes[i][j]]++;
                break;
            }

    for (int i = 0; i < n; i++)
    {
        if (candidates[i] > all / 2)
        {
            cout << names[i] << endl;
            return 0;
        }
        if (!eliminates[i])
        {
            mn = min(mn, candidates[i]);
            mx = max(mx, candidates[i]);
        }
    }

    if (mn == mx)
        return 1;

    return 2;
}

void eliminate(int n, vector<string> names, vector<vector<int>> votes)
{
    vector<int> eliminates(n, 0);
    int left = n;
    while (left > 1)
    {
        vector<int> candidates(n);
        int mn = 999999, mx = 0;

        int res = winner(votes, eliminates, candidates, names, mn, mx);

        if (!res || res == 1)
            break;

        for (int i = 0; i < n; i++)
            if (mn == candidates[i])
            {
                eliminates[i] = 1;
                left--;
            }
    }

    for (int i = 0; i < n; i++)
        if (!eliminates[i])
            cout << names[i] << endl;
}