#include "../BigInt/BigInt.hpp"

using namespace std;

int main()
{
    string a, cmd, b;

    while (cin >> a >> cmd >> b)
    {

        BigInt res;
        if (cmd == "/")
        {
            res = BigInt(a) / BigInt(b);
        }
        else
        {
            res = BigInt(a) % BigInt(b);
        }

        cout << res << "\n";
    }
}
