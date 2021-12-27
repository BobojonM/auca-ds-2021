#include "../BigInt/BigInt.hpp"

using namespace std;

int main()
{
    string a, b;

    int t;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        cout << BigInt(a) - BigInt(b) << "\n";
    }
}
