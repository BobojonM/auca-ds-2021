

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, a;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        int preva = a, left = 0, right = 0, ln = 0;
        for (int j = 0; j < 9; j++)
        {
            cin >> a;
            if (preva >= a)
                left++;
            if (preva <= a)
                right++;
            ln++;
            preva = a;
        }

        if (ln == left || ln == right)
            arr[i] = 1;
    }

    cout << "Lumberjacks:\n";
    for (int i = 0; i < n; i++)
        cout << (arr[i] == 1 ? "Ordered" : "Unordered") << "\n";
}