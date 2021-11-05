#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void printPuzzle(const vector<string> &puzzle, const int &puzzleNumber, const bool &error);
void move(vector<string> &pazzle, bool &valid, int &x, int &y);
const map<char, int> moveX = {
    {'A', 0},
    {'B', 0},
    {'R', 1},
    {'L', -1},
};
const map<char, int> moveY = {
    {'A', -1},
    {'B', 1},
    {'R', 0},
    {'L', 0},
};

int main()
{
    vector<string> pazzle(5);

    string lineBlank = "";
    for (int t = 1;; ++t)
    {
        int x(-1), y(-1);

        for (int i = 0; i < 5; ++i)
        {
            getline(cin, pazzle[i]);

            for (int j = 0; j < 5; ++j)
            {
                if (pazzle[i][j] == 'Z')
                    return 0;

                if (pazzle[i][j] == ' ')
                {
                    x = j;
                    y = i;
                }
            }
        }

        cout << lineBlank;
        lineBlank = '\n';

        bool valid(true);
        move(pazzle, valid, x, y);
        printPuzzle(pazzle, t, valid);
    }
}

void move(vector<string> &pazzle, bool &valid, int &x, int &y)
{
    char move;

    while (cin >> move && move != '0')
    {
        int nX(x + moveX.at(move)), nY(y + moveY.at(move));

        if (nX < 0 || nX >= 5 || nY < 0 || nY >= 5)
            valid = false;

        if (valid)
        {
            swap(pazzle[nY][nX], pazzle[y][x]);
            x = nX;
            y = nY;
        }

        cin >> move;
    }
}

void printPuzzle(const vector<string> &pazzle, const int &puzzleNumber, const bool &valid)
{
    cout << "Puzzle #" << puzzleNumber << ":\n";

    if (valid)
    {
        for (int y = 0; y < 5; ++y)
        {
            string space = "";
            for (int x = 0; x < 5; ++x)
            {
                cout << space << pazzle[y][x];
                space = " ";
            }

            cout << '\n';
        }
    }

    else
        cout << "This puzzle has no final configuration.\n";

    cin.ignore();
}
