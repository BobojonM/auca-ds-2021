#include "../BigInt/BigInt.hpp"
using namespace std;

int main()
{
    int n, a;

    while (cin >> n >> a)
    {
        BigInt res(a);
        BigInt t(a);

        for (int i = 2; i <= n; ++i)
        {
            t *= a;
            res += (t * i);
        }

        cout << res << "\n";
    }
}