#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Team
{
    string name;
    int wins;
    int ties;
    int losses;
    int goalScored;
    int goalAgainst;

    int totalPoints;
    int gamesPlayed;
    int goalDiff;
};

int totalScoreA(Team a, Team b)
{
    int total = 0;

    total += a.totalPoints > b.totalPoints;
    total += a.wins > b.wins;
    total += a.goalDiff > b.goalDiff;
    total += a.goalScored > b.goalScored;
    total += a.gamesPlayed < b.gamesPlayed;

    return total;
}

struct CmpByName
{
    bool operator()(const Team &a, const Team &b) const
    {
        return a.name < b.name;
    }
};

struct CmpByResult
{
    bool operator()(const Team &a, const Team &b) const
    {
        int total1 = totalScoreA(a, b);
        int total2 = totalScoreA(b, a);

        if (total1 == total2)
        {
            return CmpByName()(a, b);
        }

        return total1 > total2;
    }
};

Team make_team(string name, int wins = 0, int ties = 0, int losses = 0, int goalScored = 0, int goalAgainst = 0)
{
    Team a;
    a.name = name;
    a.wins = wins;
    a.ties = ties;
    a.losses = losses;
    a.goalScored = goalScored;
    a.goalAgainst = goalAgainst;

    return a;
}

Team update_team(Team a, int goalScored = 0, int goalAgainst = 0)
{
    Team b = a;
    if (goalScored > goalAgainst)
        b.wins++;
    else if (goalScored < goalAgainst)
        b.losses++;
    else
        b.ties++;
    b.goalScored += goalScored;
    b.goalAgainst += goalAgainst;

    b.totalPoints = b.wins * 3 + b.ties;
    b.gamesPlayed = b.wins + b.ties + b.losses;
    b.goalDiff = b.goalScored - b.goalAgainst;

    return b;
}

int main()
{
    iostream::sync_with_stdio(false);

    string line;

    //cases
    int x;
    cin >> x;
    getline(cin, line);
    for (int test = 0; test < x; test++)
    {
        if (test)
            cout << "\n";

        vector<Team> vc;

        string tournament;
        getline(cin, tournament);

        //reading tournament name
        int teams;
        string name;
        cin >> teams;
        getline(cin, line);

        //reading team names
        for (int i = 0; i < teams; i++)
        {
            getline(cin, name);
            Team a = make_team(name);
            vc.push_back(a);
        }

        sort(vc.begin(), vc.end(), [](Team a, Team b)
             { return a.name < b.name; });

        int games;
        string result;
        cin >> games;
        getline(cin, line);

        //reading results
        for (int i = 0; i < games; i++)
        {
            string str = "", team1, team2;
            int teamScore1, teamScore2;

            getline(cin, result);

            int t = 1;
            for (int j = 0; j < sz(result); j++)
            {
                char ch = result[j];
                if (!(ch == '#' || ch == '@'))
                    str += ch;

                //team1 name
                if (ch == '#' && t == 1)
                {
                    team1 = str;
                    str = "";
                    t++;
                }

                //team1 Score
                if (ch == '@')
                {
                    stringstream geek(str);
                    geek >> teamScore1;
                    str = "";
                }

                //team2 Score
                if (ch == '#' && t == 2)
                {
                    stringstream geek(str);
                    geek >> teamScore2;
                    str = "";
                }
            }
            //team2 name
            team2 = str;

            //updating team1 results
            auto it = lower_bound(vc.begin(), vc.end(), team1, [](Team a, string name1)
                                  { return a.name < name1; });
            *it = update_team(*it, teamScore1, teamScore2);

            //updating team2 results
            auto it2 = lower_bound(vc.begin(), vc.end(), team2, [](Team a, string name1)
                                   { return a.name < name1; });
            *it2 = update_team(*it2, teamScore2, teamScore1);
        }

        //Sorting by rules
        sort(vc.begin(), vc.end(), CmpByResult());

        //Printing
        cout << tournament << endl;
        for (int i = 0; i < sz(vc); i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, vc[i].name.c_str(), vc[i].totalPoints, vc[i].gamesPlayed, vc[i].wins, vc[i].ties, vc[i].losses, vc[i].goalDiff, vc[i].goalScored, vc[i].goalAgainst);
        }
    }
}