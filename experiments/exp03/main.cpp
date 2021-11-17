#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    ostringstream sout;

    double kPI = 3.1415926;

    sout << fixed << setprecision(4) << kPI;

    cout << sout.str().substr(2, 3) << endl;

    istringstream sinp("11:23:03");

    int sec;
    int min;
    int hours;
    char ch;
    sinp >> sec >> ch >> min >> ch >> hours;

    cout << sec << endl;
    cout << min << endl;
    cout << hours << endl;

    for (string line; getline(cin, line);)
    {
        int r = 0;
        istringstream sinp2(line);
        for (string w; sinp2 >> w;)
        {
            cout << w << endl;
            ++r;
        }
        cout << "number of words: " << r << endl;
    }
}