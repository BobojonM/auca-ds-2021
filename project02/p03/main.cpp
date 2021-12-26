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

        //cout << r << " " << c << " " << m << " " << n;

        sort(vc.begin(), vc.end(), [](Freq a, Freq b)
             { return a.count > b.count; });

        int freq = (*(vc.begin())).count;

        for (vector<Freq>::iterator a = vc.begin(); a < vc.end() - 1; a++)
        {
            if ((*a).count == (*(1 + a)).count)
                freq += (*a).count;
            else
                break;
        }

        // cout << (*(vc.begin())).letter << " " << (*(vc.begin())).count << endl;
        // cout << (*(1 + vc.begin())).letter << " " << (*(1 + vc.begin())).count << endl;
        // cout << (*(2 + vc.begin())).letter << " " << (*(2 + vc.begin())).count << endl;
        // cout << (*(3 + vc.begin())).letter << " " << (*(3 + vc.begin())).count << endl;
        // cout << (*(4 + vc.begin())).letter << " " << (*(4 + vc.begin())).count << endl;
        // cout << (*(5 + vc.begin())).letter << " " << (*(5 + vc.begin())).count << endl;

        // cout << freq << endl;

        int nfreq = r * c - freq;

        cout << "Case " << test << ": " << freq * m + nfreq * n << endl;
    }
}