#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int grade;

    while (cin >> name >> grade)
    {
        cout << name << " " << grade << "\n";
    }
}