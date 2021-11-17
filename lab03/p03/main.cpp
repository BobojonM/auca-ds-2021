#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void runGame(vector<vector<string>> players);
void winner(vector<vector<string>> players);
void pop(int pID, string &card, vector<vector<string>> &players, vector<string> &cards, int &ind);

int main()
{
    vector<vector<string>> players(2);

    string line;
    for (int l = 1, i = 1; getline(cin, line) && line != "#"; l++)
    {
        istringstream sinp(line);
        string card;

        for (; sinp >> card; i++)
            players[!(i % 2)].push_back(card);

        if (l % 4 == 0)
        {
            runGame(players);
            players[0].clear();
            players[1].clear();
        }
    }
}

void runGame(vector<vector<string>> players)
{
    string card;
    vector<string> cards;

    for (int ind, pID = 0; (!players[pID].empty());)
    {
        pop(pID, card, players, cards, ind);
        pID = (pID == 0) ? 1 : 0;

        for (int ind2, t = ind + 1; t && !players[pID].empty();)
        {
            pop(pID, card, players, cards, ind2);
            if (ind2 + 1)
            {
                pID = (pID == 0) ? 1 : 0;
                t = ind2 + 1;
            }
            else
                t--;
        }

        if (ind + 1 && !players[pID].empty())
        {
            pID = (pID == 0) ? 1 : 0;
            players[pID].insert(players[pID].begin(), cards.rbegin(), cards.rend());
            cards.clear();
        }
    }

    winner(players);
}

void winner(vector<vector<string>> players)
{
    cout << setw(2);
    if (players[0].empty())
        cout << "1 " << players[1].size();
    else
        cout << "2 " << players[0].size();
    cout << "\n";
}

void pop(int pID, string &card, vector<vector<string>> &players, vector<string> &cards, int &ind)
{
    string faceCards = "JQKA";
    card = players[pID].back();
    players[pID].pop_back();
    cards.push_back(card);
    ind = faceCards.find(card[1]);
}