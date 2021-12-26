#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int ascii;
    int value;
};

Pair makePair(int ascii, int value)
{
    Pair a;
    a.ascii = ascii;
    a.value = value;
    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    bool notFirstline = false;
    while (getline(cin, line))
    {
        if (notFirstline)
            cout << "\n";

        vector<Pair> vc;
        for (char ch : line)
        {
            auto it = lower_bound(vc.begin(), vc.end(), ch, [](Pair a, char w)
                                  { return a.ascii < w; });

            if (it != vc.end())
            {
                if ((*it).ascii == ch)
                {
                    (*it).value++;
                }
                else
                {
                    Pair a = makePair(ch, 1);
                    vc.insert(it, a);
                }
            }
            else
            {
                Pair a = makePair(ch, 1);
                vc.push_back(a);
            }
        }

        sort(vc.begin(), vc.end(), [](Pair a, Pair b)
             { return a.value < b.value; });

        for (auto e : vc)
        {
            cout << e.ascii << " " << e.value << "\n";
        }

        notFirstline = true;
    }
}