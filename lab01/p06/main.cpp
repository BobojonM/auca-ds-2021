#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename C>
string containerToStr(const C &c)
{
    ostringstream sinp;

    sinp << "{";

    bool isFirst = true;
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sinp << ", ";
        }
        sinp << e;
        isFirst = false;
    }

    sinp << "}";

    return sinp.str();
}

TEST_CASE("vector`s default constructor")
{
    vector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("vector's counstructor with size")
{
    vector<int> v(5);
    REQUIRE(v.size() == 5);

    vector<string> v2(3);
    REQUIRE(v2.size() == 3);

    vector<int> v3(3, 42);
    REQUIRE(v3.size() == 3);
}

TEST_CASE("vector`s constructor with count copies")
{
    vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v2(3);

    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0].empty());
    REQUIRE(v2[1].empty());
    REQUIRE(v2[2].empty());

    vector<int> v3(3, 42);
    REQUIRE(v3.size() == 3);
    REQUIRE(v3[0] == 42);
    REQUIRE(v3[1] == 42);
    REQUIRE(v3[2] == 42);
}

TEST_CASE("vector`s copy constructor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = v;
    v[1] = 1000;

    REQUIRE(v2[1] != v[1]);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("vector`s move constructor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = move(v);

    REQUIRE(v.empty());
    REQUIRE(v2.size() == 3);

    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("vector's move assignment operator")
{
    vector<int> v = {1, 2, 3};

    vector<int> v2 = {10, 20};

    v2 = move(v);

    REQUIRE(v2.size() == 3);
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
    REQUIRE(v.empty());
}

TEST_CASE("vector`s assignment operator")
{
    vector<int> v = {1, 2, 3};

    vector<int> v2 = {10, 20};

    v2 = v;

    REQUIRE(v2.size() == 3);
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");

    v[1] = 1000;

    REQUIRE(containerToStr(v) == "{1, 1000, 3}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
}

TEST_CASE("vector`s at operator")
{
    vector<int> v = {10, 20, 30};

    REQUIRE_THROWS_AS(v.at(3), out_of_range);
}

TEST_CASE("vector's methods front(), back()")
{
    vector<int> v = {4, 1, 2, 7, 6};

    REQUIRE(v.front() == 4);

    v.front() = 10;

    REQUIRE(v.front() == 10);

    REQUIRE(v.back() == 6);

    v.back() = 11;

    REQUIRE(v.back() == 11);
}

struct Student
{
    int mID;
    int mBirthYear;
    Student(int ID, int birthYear)
        : mID(ID), mBirthYear(birthYear)
    {
    }

    int getID() const
    {
        return mID;
    }
};

TEST_CASE("vector< T>::iterator")
{
    vector<int> v = {10, 5, 2, 3};

    // vector<int> ::iterator it = v.begin();

    auto it = v.begin();

    REQUIRE(*it == 10);

    ++it;
    REQUIRE(*it == 5);

    REQUIRE(*++it == 2);
    REQUIRE(*it++ == 2);
    REQUIRE(*it == 3);

    auto it2 = v.end();
    REQUIRE(it != it2);
    REQUIRE(it < it2);

    --it2;
    REQUIRE(*it2 == 3);

    it2 -= 2;

    REQUIRE(*it2 == 5);

    REQUIRE(it2 - v.begin() == 1);

    vector<Student> s = {{1001, 2003}, {1002, 2004}};

    auto it3 = s.begin();

    REQUIRE((*it3).mBirthYear == 2003);
    REQUIRE(it3->mBirthYear == 2003);
    REQUIRE(it3->getID() == 1001);
}

TEST_CASE("vector<T> erase() operator")
{
    vector<int> vc = {7, 20, 40, 80, 5};

    auto it = vc.begin();
    ++it;

    vc.erase(it);

    REQUIRE(vc.size() == 4);
    REQUIRE(containerToStr(vc) == "{7, 40, 80, 5}");

    auto it2 = vc.begin();

    vc.erase(it2, it2 + 2);

    REQUIRE(vc.size() == 2);
    REQUIRE(containerToStr(vc) == "{80, 5}");
}

TEST_CASE("vector< T> insert() operator")
{

    vector<int> vc = {1, 2, 3};

    auto it = vc.begin();
    ++it;

    vc.insert(it, 4);

    REQUIRE(vc.size() == 4);
    REQUIRE(containerToStr(vc) == "{1, 4, 2, 3}");

    auto it2 = vc.begin();

    vc.insert(it2 + 2, 3, 3);

    REQUIRE(vc.size() == 7);
    REQUIRE(containerToStr(vc) == "{1, 4, 3, 3, 3, 2, 3}");
}