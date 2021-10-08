#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int y;
    cin >> y;

    swap(x, y);

    cout << x << " " << y << endl;
    cout << min(x, y) << endl;

    string a;
    cin >> a;

    string b;
    cin >> b;

    swap(a, b);
    cout << a << " " << b << endl;
    cout << min(a, b) << endl;
}