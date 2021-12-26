#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char letter;
    int count;
};

Freq make_freq(char letter, int count)
{
    Freq a;
    a.letter = letter;
    a.count = count;

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    int x;
    cin >> x;
    for (int test = 1; test <= x; test++)
    {
        int r, c, m, n;
        cin >> r >> c >> m >> n;

        vector<Freq> vc;
        char ch;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> ch;
                auto it = lower_bound(vc.begin(), vc.end(), ch, [](Freq a, char w)
                                      { return a.letter < w; });

                if (it != vc.end())
                {
                    if ((*it).letter == ch)
                    {
                        (*it).count++;
                    }
                    else
                    {
                        Freq a = make_freq(ch, 1);
                        vc.insert(it, a);
                    }
                }
                else
                {
                    Freq a = make_freq(ch, 1);
                    vc.push_back(a);
                }
            }
        }

        sort(vc.begin(), vc.end(), [](Freq a, Freq b)
             { return a.count < b.count; });

        int freq = (*(--vc.end())).count;

        for (vector<Freq>::iterator a = --vc.end(); a > vc.begin(); a--)
        {
            if ((*a).count == (*(--a)).count)
                freq += (*a).count;
            else
                break;
        }

        int nfreq = r * c - freq;

        cout << "Case " << test << ": " << freq * m + nfreq * n << endl;
    }
}