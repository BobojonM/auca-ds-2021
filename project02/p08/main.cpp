#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void action1(vector<int> vc)
{
    bool a = true;
    for (int x : vc)
    {
        int y = 7777 - x;
        auto it = lower_bound(vc.begin(), vc.end(), y);

        if (it != vc.end())
        {
            if (*it == y)
            {
                cout << "Yes\n";
                a = false;
                break;
            }
        }
    }

    if (a)
        cout << "No\n";
}

void action2(vector<int> vc)
{
    int sum = 0;
    for (int x : vc)
    {
        auto it = lower_bound(vc.begin(), vc.end(), x);
        auto it2 = upper_bound(vc.begin(), vc.end(), x);

        sum += it2 - it;
    }

    cout << (sum == sz(vc) ? "Unique\n" : "Contains duplicate\n");
}

void action3(vector<int> vc, int n)
{
    bool a = true;
    for (int x : vc)
    {
        auto it = lower_bound(vc.begin(), vc.end(), x);
        auto it2 = upper_bound(vc.begin(), vc.end(), x);

        if (it2 - it > n / 2)
        {
            cout << *it << endl;
            a = false;
            break;
        }
    }

    if (a)
        cout << -1 << endl;
}

void action4(vector<int> vc, int n)
{
    if (n % 2 == 1)
        cout << vc[n / 2] << endl;
    else
        cout << vc[n / 2 - 1] << " " << vc[n / 2] << endl;
}

void action5(vector<int> vc, int n)
{
    bool a = false;
    for (int i = 0; i < n; i++)
    {
        if (100 <= vc[i] && vc[i] <= 999)
        {
            if (a)
                cout << " ";

            cout << vc[i];

            a = true;
        }
    }
    cout << endl;
}

int main()
{
    iostream::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;

    vector<int> vc(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << vc[i] << " ";
    // }
    // cout << "\n";

    if (t == 1)
    {
        action1(vc);
    }
    else if (t == 2)
    {
        action2(vc);
    }
    else if (t == 3)
    {
        action3(vc, n);
    }
    else if (t == 4)
    {
        action4(vc, n);
    }
    else if (t == 5)
    {
        action5(vc, n);
    }
}