#include "../BigInt/BigInt.hpp"
using namespace std;

int main()
{
    int n, friends;
    int cases = 1;

    while (cin >> n >> friends && n && friends)
    {
        BigInt res(0);

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            res += BigInt(s);
        }

        cout << "Bill #" << cases << "costs " << res << ": each friend should pay " << res / friends << "\n\n";

        cases++;
    }
}