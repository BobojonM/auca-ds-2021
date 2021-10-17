

#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int strToInt(string name)
{
    int n1 = 0;
    for (auto ch : name)
        if (isalpha(ch))
            n1 += (toupper(ch) - 64);
    return n1;
}

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

    string name1, name2;
    while (getline(cin, name1))
    {
        getline(cin, name2);

        int n1 = sumDigits(strToInt(name1));
        int n2 = sumDigits(strToInt(name2));

        cout << fixed << setprecision(2) << ((double)min(n1, n2) / max(n1, n2)) * 100 << " %" << endl;
    }
}