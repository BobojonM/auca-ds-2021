#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<char> keyboard = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.'};
    string word;

    for (int i = 0; cin >> word; i++)
    {
        if (i)
            cout << " ";
        for (int j = 0; j < (int)word.length(); j++)
            cout << keyboard[(find(keyboard.begin(), keyboard.end(), tolower(word[j])) - keyboard.begin()) - 2];
    }
    cout << "\n";
}
