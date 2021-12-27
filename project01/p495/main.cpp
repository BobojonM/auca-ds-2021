#include "../BigInt/BigInt.hpp"

using namespace std;

vector<BigInt> f(5001, 0);

void fillFib()
{
    if (f[0] == BigInt(0))
    {
        f[1] = BigInt(1);
        f[2] = BigInt(1);

        for (int i = 3; i < 5001; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]);
        }
    }
}

int main()
{
    fillFib();

    int n;
    while (cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is " << f[n] << "\n";
    }
}
