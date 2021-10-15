#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    v1[1] = 42;
    cout << v1[3] << "\n";

    cout << sz(v1) << "\n";
    cout << v1.capacity() << "\n";

    for (auto e : v1)
    {
        cout << " " << e;
    }
    cout << "\n";

    int n;
    cin >> n;
    vector<int> v2(n);
    for (auto e : v2)
    {
        cout << " " << e;
    }
    cout << "\n";

    vector<string> v3(n);
    v3[n - 1] += "Hello";
    v3[n - 1] += " World!";
    for (auto e : v3)
    {
        cout << " " << e;
    }
    cout << "\n";

    vector<int> v4 = {1, 2, 3, 4};
    cout << v4[3] << "\n";
}