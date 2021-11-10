#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Computer
{
    vector<int> reg;
    vector<int> ram;
    int ins;

    void runCommand2(int d, int n)
    {
        reg[d] = n;
    }
    void runCommand3(int d, int n)
    {
        reg[d] += n;
        reg[d] %= 1000;
    }
    void runCommand4(int d, int n)
    {
        reg[d] *= n;
        reg[d] %= 1000;
    }
    void runCommand5(int d, int n)
    {
        reg[d] = reg[n];
    }
    void runCommand6(int d, int n)
    {
        reg[d] += reg[n];
        reg[d] %= 1000;
    }
    void runCommand7(int d, int n)
    {
        reg[d] *= reg[n];
        reg[d] %= 1000;
    }
    void runCommand8(int d, int n)
    {
        reg[d] = ram[reg[n]];
    }
    void runCommand9(int d, int n)
    {
        ram[reg[n]] = reg[d];
    }
    void runCommand0(int d, int n)
    {
        if (reg[n] != 0)
            ins = reg[d];
    }

public:
    Computer()
        : reg(10, 0), ram(1000, 0), ins(0)
    {
    }

    void readCommands(istream &inp)
    {
        int i = 0;
        for (string line; getline(inp, line) && !line.empty();)
        {
            ram[i] = stoi(line);
            ++i;
        }
    }

    int run()
    {
        int res = 1;
        for (; ram[ins] != 100;)
        {
            int d2 = ram[ins] % 10;
            int d1 = ram[ins] % 100 / 10;
            int d = ram[ins] / 100;
            ins++;
            res++;

            switch (d)
            {
            case 2:
                runCommand2(d1, d2);
                break;
            case 3:
                runCommand3(d1, d2);
                break;
            case 4:
                runCommand4(d1, d2);
                break;
            case 5:
                runCommand5(d1, d2);
                break;
            case 6:
                runCommand6(d1, d2);
                break;
            case 7:
                runCommand7(d1, d2);
                break;
            case 8:
                runCommand8(d1, d2);
                break;
            case 9:
                runCommand9(d1, d2);
                break;
            case 0:
                runCommand0(d1, d2);
                break;
            }
        }

        return res;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests >> ws;
    for (int i = 0; i < tests; i++)
    {
        Computer comp;

        comp.readCommands(cin);

        if (i)
            cout << "\n";
        cout << comp.run() << "\n";
    }
}
