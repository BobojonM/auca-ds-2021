#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Submission
{
    int consestant;
    int problem;
    int time;
    string l;
};

struct Team
{
    int number;
    int solvedProblems;
    int penalty;

    Team()
        : number(0), solvedProblems(0), penalty(0)
    {
    }

    Team(int n, int sp, int p)
        : number(n), solvedProblems(sp), penalty(p)
    {
    }

    void TeamUpdate(int sp, int p)
    {
        solvedProblems += sp;
        penalty += p;
    }
};

int totalScore(Team a, Team b)
{
    int total = 0;

    total += (a.solvedProblems > b.solvedProblems) * 32;
    total += (a.penalty < b.penalty) * 16;

    return total;
}

struct CmpTeamByNumber
{
    bool operator()(const Team &a, const Team &b) const
    {
        return a.number < b.number;
    }
};

struct CmpTeamByACMRules
{
    bool operator()(const Team &a, const Team &b) const
    {
        int total1 = totalScore(a, b);
        int total2 = totalScore(b, a);

        if (total1 == total2)
        {
            return CmpTeamByNumber()(a, b);
        }

        return total1 > total2;
    }
};

Submission make_submission(int consestant, int problem, int time, string l)
{
    Submission a;

    a.consestant = consestant;
    a.problem = problem;
    if (l == "I")
        a.time = 20;
    else if (l == "C")
        a.time = time;
    else
        a.time = 0;
    a.l = l;

    return a;
}

int main()
{
    iostream::sync_with_stdio(false);

    int x;
    string tests;
    getline(cin, tests);
    stringstream s(tests);
    s >> x;
    getline(cin, tests);

    for (int test = 0; test < x; test++)
    {
        if (test)
            cout << "\n";

        vector<Submission> vc;
        int contestant, problem, time;
        string line, l;
        set<int> teams;
        map<int, Team> tm;

        while (getline(cin, line) && !line.empty())
        {
            stringstream inp(line);
            inp >> contestant >> problem >> time >> l;
            tm[contestant] = Team(contestant, 0, 0);

            teams.insert(contestant);

            auto it = find_if(vc.begin(), vc.end(), [contestant, problem](Submission a)
                              { return a.consestant == contestant && a.problem == problem; });

            if (it != vc.end())
            {
                if ((*it).l == "I" && l == "C")
                {
                    (*it).l = "C";
                    (*it).time += time;
                }
                else if ((*it).l == "I" && l == "I")
                {
                    (*it).time += 20;
                }
            }
            else if (l == "C" || l == "I")
            {
                vc.push_back(make_submission(contestant, problem, time, l));
            }
        }

        sort(vc.begin(), vc.end(), [](Submission a, Submission b)
             { return a.consestant < b.consestant; });

        for (Submission e : vc)
        {

            for (int id : teams)
            {
                //cout << id << endl;
                if (e.consestant == id)
                {
                    int sp = 0;
                    int pen = 0;
                    if (e.l == "C")
                    {
                        sp += 1;
                        pen = e.time;
                    }

                    tm[id].TeamUpdate(sp, pen);
                }
            }
        }

        vector<Team> vt;
        for (int id : teams)
        {
            vt.push_back(tm[id]);
        }

        sort(vt.begin(), vt.end(), CmpTeamByACMRules());

        for (auto e : vt)
        {
            cout << e.number << " " << e.solvedProblems << " " << e.penalty << "\n";
        }
    }
}