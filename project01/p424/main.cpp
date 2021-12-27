
#include "../BigInt/BigInt.hpp"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    BigInt a(0);
    while (cin >> s && s != "0")
    {
        a += BigInt(s);
    }
    cout << a << "\n";
}