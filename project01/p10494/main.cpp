#include "../BigInt/BigInt.hpp"

using namespace std;

int main()
{
    string a, cmd, b;

    while (cin >> a >> cmd >> b)
    {
        if (cmd == "/")
        {
            cout << BigInt(a) / BigInt(b) << "\n";
        }
        else
        {
            cout << BigInt(a) % BigInt(b) << "\n";
        }
    }
}
