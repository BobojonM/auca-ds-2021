#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#include "../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;

    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

// supporr call operator: T t; t()

struct IsEven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

void p0101()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 not found" << endl;
    }

    auto itV = find(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of 20 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "-1 not found" << endl;
    }
}

void p0102()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 not found" << endl;
    }

    auto itV = auFind(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of 20 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "-1 not found" << endl;
    }
}

void p0201()
{
    //vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //IsEven functor;
    //auto itV = find_if(begin(v), end(v), IsEven());
    //if (itV != end(v))
    //{
    //    cout << "position of the first even number is " << itV - begin(v) << endl;
    //    cout << "the number is " << *itV << endl;
    //}
    //else
    //{
    //    cout << "even numbers not found" << endl;
    //}

    vector<int> v2 = {3, 1, 20, 4, 7, 0, 5};

    //lambda expression;
    auto itV2 = find_if(begin(v2), end(v2), [](int value)
                        { return value % 2 == 0; });

    if (itV2 != end(v2))
    {
        cout << "position of the first even number is " << itV2 - begin(v2) << endl;
        cout << "the number is " << *itV2 << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }
}

void p0202()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    //IsEven functor;
    auto itV = auFindIf(begin(v), end(v), IsEven());
    if (itV != end(v))
    {
        cout << "position of the first even number is " << itV - begin(v) << endl;
        cout << "the number is " << *itV << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }

    vector<int> v2 = {3, 1, 20, 4, 7, 0, 5};

    //lambda expression;
    auto itV2 = auFindIf(begin(v2), end(v2), [](int value)
                         { return value % 2 == 0; });

    if (itV2 != end(v2))
    {
        cout << "position of the first even number is " << itV2 - begin(v2) << endl;
        cout << "the number is " << *itV2 << endl;
    }
    else
    {
        cout << "even numbers not found" << endl;
    }
}

struct GreaterThan
{
    int mData;
    GreaterThan(int data)
        : mData(data)
    {
    }

    bool operator()(int value) const
    {
        return value > mData;
    }
};

void p03()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    cout << "x = ";
    int x;
    cin >> x;

    auto it = find_if(begin(v), end(v), GreaterThan(x));
    if (it != end(v))
    {
        cout << "the index: " << it - begin(v) << endl;
        cout << "the value: " << *it << endl;
    }
    else
    {
        cout << "Value greater than " << x << " not found" << endl;
    }

    auto it2 = find_if(begin(v), end(v), [x](int value)
                       { return value > x; });
    if (it2 != end(v))
    {
        cout << "the index: " << it2 - begin(v) << endl;
        cout << "the value: " << *it2 << endl;
    }
    else
    {
        cout << "Value greater than " << x << " not found" << endl;
    }
}

struct CmpByGpa
{
    bool operator()(const Student &s1, Student &s2) const
    {
        return s1.mGpa < s2.mGpa;
    }
};

void p06()
{
    vector<Student> stud;

    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        //stud.push_back(Student(name, gpa));
        stud.emplace_back(name, gpa);
    }

    sort(begin(stud), end(stud), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &s : stud)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }

    cout << "---------------------------------------------------" << endl;

    sort(begin(stud), end(stud), CmpByGpa());

    for (const auto &s : stud)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }
}

void p07()
{
    vector<Student> students = {
        {"C", 3.45},
        {"Z", 4.00},
        {"X", 4.00},
        {"Y", 3.00},
        {"W", 4.00},
        {"E", 4.00},
        {"R", 3.00},
        {"T", 4.00},
        {"D", 2.45},
        {"A", 3.00},
    };

    cout << "------------- Regular sort -------------" << endl;

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "-------------" << endl;

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa < s2.mGpa; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "------------- Stable sort -------------" << endl;

    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "-------------" << endl;

    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mGpa < s2.mGpa; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

int main()
{
    //p0101();
    //p0102();

    //p0201();
    //p0202();

    //p03();

    //p06();

    //p07();
}
