#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    for (string line; getline(cin, line);)
    {
        string buff;
        for (auto c : line)
        {
            if (isalpha(c))
            {
                buff += tolower(c);
            }
        }
        // value semantics
        string temp = buff;
        reverse(buff.begin(), buff.end());

        cout << (buff == temp ? "palindrom" : "not a polindrome") << "\n";
    }
}