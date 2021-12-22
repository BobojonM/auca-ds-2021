#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <utility>
#include <tuple>

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

void p0401()
{
    vector<int> vc;
    int x;

    while (cin >> x)
    {
        vc.push_back(x);
    }

    auto it = min_element(begin(vc), end(vc));

    if (it != end(vc))
    {
        cout << "index of it: " << it - begin(vc) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0402()
{
    vector<int> vc;
    int x;

    while (cin >> x)
    {
        vc.push_back(x);
    }

    auto it = auMinElement(begin(vc), end(vc));

    if (it != end(vc))
    {
        cout << "index of it: " << it - begin(vc) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0501()
{
    vector<Student> students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    cout << "student with min name gpa" << endl;
    auto it = min_element(begin(students), end(students), [](Student s, Student min)
                          { return s.mGpa < min.mGpa; });

    if (it != end(students))
    {
        cout << "index: " << it - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "student with min name (lexicographically)" << endl;
    auto it2 = min_element(begin(students), end(students), [](Student s, Student min)
                           { return s.mName < min.mName; });

    if (it2 != end(students))
    {

        cout << "index: " << it2 - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0502()
{
    vector<Student> students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    cout << "student with min name gpa" << endl;
    auto it = auMinElement(begin(students), end(students), [](Student s, Student min)
                           { return s.mGpa < min.mGpa; });

    if (it != end(students))
    {
        cout << "index: " << it - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    cout << "student with min name (lexicographically)" << endl;
    auto it2 = auMinElement(begin(students), end(students), [](Student s, Student min)
                            { return s.mName < min.mName; });

    if (it2 != end(students))
    {

        cout << "index: " << it2 - begin(students) << endl;
    }
    else
    {
        cout << "not found" << endl;
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

void p08()
{
    vector<pair<string, double>> students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    cout << "-------------" << endl;

    sort(begin(students), end(students));

    for (const auto &s : students)
    {
        cout << s.first << ", " << s.second << endl;
    }
}

void p09()
{
    using Employee = tuple<string, int, double>;
    vector<Employee> employees;
    string name;
    int age;
    double salary;

    while (cin >> name >> age >> salary)
    {
        employees.emplace_back(name, age, salary);
    }

    cout << "-------------" << endl;

    sort(begin(employees), end(employees), [](const Employee &e1, const Employee &e2)
         { return get<1>(e1) < get<1>(e2); });

    for (const auto &s : employees)
    {
        cout << get<0>(s) << ", " << get<1>(s) << ", " << get<2>(s) << endl;
    }
}

void p1001()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 40, 45};
    int x;

    sort(begin(v), end(v));

    while (cin >> x)
    {
        if (binary_search(begin(v), end(v), x))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

void p1002()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 40, 45};
    int x;

    while (cin >> x)
    {
        if (auBinarySearch(begin(v), end(v), x))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}

void p11()
{
    vector<int> v = {1, 4, 5, 10, 12, 20, 40, 45};
    int x;

    while (cin >> x)
    {
        auto it = lower_bound(begin(v), end(v), x);
        if (it == end(v))
        {
            cout << "no element is equal or greater than " << x << endl;
        }
        else if (*it == x)
        {
            cout << "index of the first element equal to " << x << " is " << it - begin(v) << endl;
        }
        else
        {
            cout << "index of the first element greater than " << x << " is " << it - begin(v) << endl;
        }
    }
}

void p12()
{
    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 35, 25, 25, 40};

    sort(begin(v), end(v));

    for (int x; cin >> x;)
    {
        auto it = equal_range(begin(v), end(v), x);
        cout << "number of occurences of " << x << " is " << it.second - it.first << endl;
    }
}

int main()
{
    //p0101();
    //p0102();

    //p0201();
    //p0202();

    //p03();

    //p0401();
    //p0402();

    //p0501();
    //p0502();

    //p06();

    //p07();

    //p08();

    //p09();

    //p1001();
    p1002();

    //p11();

    //p12();
}
