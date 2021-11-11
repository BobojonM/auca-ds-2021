#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class World
{
    vector<vector<int>> columns;
    vector<int> block, tmp;

public:
    World()
        : columns(25), block(25)
    {
    }

    void fill(int a)
    {
        while (columns[block[a]].back() != a)
        {
            int t = columns[block[a]].back();
            columns[t].push_back(t);
            block[t] = t;
            columns[block[a]].pop_back();
        }
    }

    void moveOnto(int a, int b)
    {
        fill(a);
        fill(b);

        columns[block[b]].pop_back();
        block[b] = b;
        columns[b].push_back(b);

        columns[b].push_back(columns[block[a]].back());
        columns[block[a]].pop_back();
        block[a] = b;
    }

    void moveOver(int a, int b)
    {
        fill(a);

        columns[block[b]].push_back(columns[block[a]].back());
        columns[block[a]].pop_back();
        block[a] = block[b];
    }

    void pileOnto(int a, int b)
    {
        fill(b);

        columns[block[b]].pop_back();
        block[b] = b;
        columns[b].push_back(b);

        while (columns[block[a]].back() != a)
        {
            tmp.push_back(columns[block[a]].back());
            columns[block[a]].pop_back();
        }

        tmp.push_back(columns[block[a]].back());
        columns[block[a]].pop_back();

        while (!tmp.empty())
        {
            columns[block[b]].push_back(tmp.back());
            block[tmp.back()] = block[b];
            tmp.pop_back();
        }
    }

    void pileOver(int a, int b)
    {
        while (columns[block[a]].back() != a)
        {
            tmp.push_back(columns[block[a]].back());
            columns[block[a]].pop_back();
        }

        tmp.push_back(columns[block[a]].back());
        columns[block[a]].pop_back();

        while (!tmp.empty())
        {
            columns[block[b]].push_back(tmp.back());
            block[tmp.back()] = block[b];
            tmp.pop_back();
        }
    }

    void run(istream &inp)
    {
        int n, a, b;
        string cmd, cmd2;

        while (inp >> n)
        {
            for (int i = 0; i < n; i++)
            {
                columns[i].push_back(i);
                block[i] = i;
            }

            while (inp >> cmd)
            {
                if (cmd[0] == 'q')
                    break;

                inp >> a >> cmd2 >> b;

                if (a != b && block[a] != block[b])
                {
                    if (cmd[0] == 'm')
                    {
                        if (cmd2[1] == 'n')
                            moveOnto(a, b);
                        else
                            moveOver(a, b);
                    }
                    else
                    {
                        if (cmd2[1] == 'n')
                            pileOnto(a, b);
                        else
                            pileOver(a, b);
                    }
                }
            }

            //print
            for (int i = 0; i < n; i++)
            {
                cout << i << ":";
                if (columns[i].empty())
                    cout << endl;
                else
                {
                    while (!columns[i].empty())
                    {
                        tmp.push_back(columns[i].back());
                        columns[i].pop_back();
                    }

                    while (!tmp.empty())
                    {
                        cout << " " << tmp.back();
                        tmp.pop_back();
                    }
                    cout << endl;
                }
            }
        }
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    World world;

    world.run(cin);
}
