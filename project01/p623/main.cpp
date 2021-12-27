#include "../BigInt/BigInt.hpp"

using namespace std;

int main()
{
    int n;
    vector<BigInt> vc(1001);

    vc[0] = vc[1] = 1;

    for (int i = 2; i <= 1000; ++i)
        vc[i] = vc[i - 1] * i;

    while (cin >> n)
    {
        cout << n << "!\n";
        cout << vc[n] << "\n";
    }
}
