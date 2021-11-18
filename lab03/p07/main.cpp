#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Game
{
    vector<vector<int>> board;
    const static int whitePawn = 1, blackPawn = 2, rook = 3, knight = 4, bishop = 5, king = 6, queen = 7;

    void putFigure(char f, int row, int col)
    {
        switch (f)
        {
        case 'r':
        case 'R':
            board[row][col] = rook;
            break;
        case 'n':
        case 'N':
            board[row][col] = knight;
            break;
        case 'b':
        case 'B':
            board[row][col] = bishop;
            break;
        case 'k':
        case 'K':
            board[row][col] = king;
            break;
        case 'q':
        case 'Q':
            board[row][col] = queen;
            break;
        case 'p':
            board[row][col] = blackPawn;
            break;
        case 'P':
            board[row][col] = whitePawn;
            break;
        }
    }

    void parse(string line)
    {
        int row = 0, col = 0;
        for (int i = 0; i < sz(line); i++)
        {
            if (isdigit(line[i]))
            {
                col += line[i] - '0';
            }
            else if (line[i] == '/')
            {
                row++;
                col = 0;
            }
            else
            {
                putFigure(line[i], row, col);
                col++;
            }
        }
    }

    void QueenAndKingMoves(int row, int col, int n)
    {
        const static vector<int> KingMovesY = {-1, -1, -1, 0, 0, 1, 1, 1};
        const static vector<int> KingMovesX = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++)
        {
            int newX = col + KingMovesX[i];
            int newY = row + KingMovesY[i];

            int cnt = 0;
            while (0 <= newX && newX <= 7 && 0 <= newY && newY <= 7 && (board[newY][newX] == 0 || board[newY][newX] == 9))
            {
                if (cnt >= n)
                    break;
                board[newY][newX] = 9;

                newX = newX + KingMovesX[i];
                newY = newY + KingMovesY[i];
                cnt++;
            }
        }
    }

    void KnightMoves(int row, int col)
    {
        const static vector<int> KnightMovesY = {-2, -2, -1, 1, -1, 1, 2, 2};
        const static vector<int> KnightMovesX = {-1, 1, -2, -2, 2, 2, -1, 1};

        for (int i = 0; i < 8; i++)
        {
            int newX = col + KnightMovesX[i];
            int newY = row + KnightMovesY[i];

            if (0 <= newX && newX <= 7 && 0 <= newY && newY <= 7 && (board[newY][newX] == 0 || board[newY][newX] == 9))
            {
                board[newY][newX] = 9;
            }
        }
    }

    void BishopMoves(int row, int col)
    {
        const static vector<int> BishopMovesY = {-1, -1, 1, 1};
        const static vector<int> BishopMovesX = {-1, 1, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int newX = col + BishopMovesX[i];
            int newY = row + BishopMovesY[i];

            while (0 <= newX && newX <= 7 && 0 <= newY && newY <= 7 && (board[newY][newX] == 0 || board[newY][newX] == 9))
            {
                board[newY][newX] = 9;

                newX = newX + BishopMovesX[i];
                newY = newY + BishopMovesY[i];
            }
        }
    }

    void RookMoves(int row, int col)
    {
        const static vector<int> RookMovesY = {-1, 0, 0, 1};
        const static vector<int> RookMovesX = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int newX = col + RookMovesX[i];
            int newY = row + RookMovesY[i];

            while (0 <= newX && newX <= 7 && 0 <= newY && newY <= 7 && (board[newY][newX] == 0 || board[newY][newX] == 9))
            {
                board[newY][newX] = 9;

                newX = newX + RookMovesX[i];
                newY = newY + RookMovesY[i];
            }
        }
    }

    void PawnMoves(int row, int col, int color)
    {
        const static vector<int> PawnMovesX = {-1, 1};
        int PawnMove = PawnMovesX[color - 1];

        int newY = row + PawnMove;

        for (int i = 0; i < 2; i++)
        {
            int newX = col + PawnMovesX[i];
            if (0 <= newX && newX <= 7 && 0 <= newY && newY <= 7 && (board[newY][newX] == 0 || board[newY][newX] == 9))
            {
                board[newY][newX] = 9;
            }
        }
    }

    int countEmptyCells()
    {
        int cnt = 0;

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (!board[i][j])
                    cnt++;

        return cnt;
    }

public:
    Game(string cnf)
        : board(vector<vector<int>>(8, vector<int>(8)))
    {
        parse(cnf);
    }

    int solve()
    {
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board[row][col] && board[row][col] < 8)
                {
                    int figure = board[row][col];
                    switch (figure)
                    {
                    case king:
                        QueenAndKingMoves(row, col, 1);
                        break;
                    case queen:
                        QueenAndKingMoves(row, col, 8);
                        break;
                    case bishop:
                        BishopMoves(row, col);
                        break;
                    case knight:
                        KnightMoves(row, col);
                        break;
                    case rook:
                        RookMoves(row, col);
                        break;
                    case blackPawn:
                        PawnMoves(row, col, blackPawn);
                        break;
                    case whitePawn:
                        PawnMoves(row, col, whitePawn);
                        break;
                    }
                }
            }
        }
        return countEmptyCells();
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    for (string cnf; getline(cin, cnf);)
    {
        Game game(cnf);
        cout << game.solve() << "\n";
    }
}
