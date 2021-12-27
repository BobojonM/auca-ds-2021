#include "../BigInt/BigInt.hpp"

#include <climits>

using namespace std;

int main()
{
    string s1, cmd, s2;
    BigInt mx(INT_MAX);

    while (cin >> s1 >> cmd >> s2)
    {
        BigInt a(s1);
        BigInt b(s2);

        cout << s1 << " " << cmd << " " << s2 << "\n";

        if (a > mx)
            cout << "first number too big\n";
        if (b > mx)
            cout << "second number too big\n";

        BigInt res;
        if (cmd == "+")
            res = (a + b);
        else
            res = (a * b);

        if (res > mx)
            cout << "result too big\n";
    }
}
