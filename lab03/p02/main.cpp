#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

vector<vector<char>> readPuzzle(const vector<string> &lines);
vector<char> readCommands(const vector<string> &lines);

int move(vector<vector<char>> &puzzle, const vector<char> &cmds);
void printPuzzle(const vector<vector<char>> &puzzle, int puzzleNumber, int error);

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> lines;
    string line;

    int puzzleNumber = 0;
    while (getline(cin, line) && line != "Z")
    {
        lines.push_back(line);

        if (line[line.length() - 1] == '0')
        {
            puzzleNumber++;
            auto puzzle = readPuzzle(lines);
            auto cmds = readCommands(lines);

            int error = move(puzzle, cmds);
            if (puzzleNumber != 1)
                cout << "\n";
            printPuzzle(puzzle, puzzleNumber, error);

            lines.clear();
        }
    }
}

int move(vector<vector<char>> &puzzle, const vector<char> &cmds)
{
    int x = 0, y = 0, ci = 0, error = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (puzzle[i][j] == ' ')
                x = i, y = j;

    static vector<char> dir = {'A', 'B', 'L', 'R'};
    static vector<int> movesX = {-1, 1, 0, 0};
    static vector<int> movesY = {0, 0, -1, 1};

    while (cmds[ci] != '0' && !error)
    {
        char cmd = cmds[ci];
        for (int k = 0; k < 4; k++)
            if (cmd == dir[k])
            {
                if ((k < 2 ? x : y) == (k % 2 == 0 ? 0 : 4))
                {
                    error = 1;
                    break;
                }
                puzzle[x][y] = puzzle[x + movesX[k]][y + movesY[k]];
                x += movesX[k];
                y += movesY[k];
            }
        ci++;
    }

    puzzle[x][y] = ' ';
    return error;
}

vector<vector<char>> readPuzzle(const vector<string> &lines)
{
    vector<vector<char>> result(5);
    for (int i = 0; i < 5; ++i)
    {
        result[i] = vector<char>(lines[i].begin(), lines[i].end());
        if (result[i].size() == 4)
            result[i].push_back(' ');
    }

    return result;
}

vector<char> readCommands(const vector<string> &lines)
{
    string cmd = "";
    for (int i = 5; i < (int)lines.size(); ++i)
        cmd += lines[i];

    vector<char> result(cmd.begin(), cmd.end());

    return result;
}

void printPuzzle(const vector<vector<char>> &puzzle, int puzzleNumber, int error)
{
    cout << "Puzzle #" << puzzleNumber << ":\n";

    if (!error)
        for (auto line : puzzle)
        {
            for (int i = 0; i < (int)line.size(); i++)
            {
                if (i != 0)
                    cout << " ";
                cout << line[i];
            }
            cout << "\n";
        }
    else
        cout << "This puzzle has no final configuration.\n";
}
