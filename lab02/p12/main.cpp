

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int sumDigits(int n)
{
    int res = 10;
    while (res > 9)
    {
        res = 0;
        while (n > 0)
        {
            res += n % 10;
            n /= 10;
        }

        n = res;
    }

    return res;
}

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    while (cin >> n && n)
    {
        cout << sumDigits(n) << "\n";
    }
}