#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("BigInt: Default constructor")
{
    BigInt a;
    ostringstream sout;
    sout << a;

    REQUIRE(sout.str() == "0");
}

TEST_CASE("BigInt: string constructor")
{
    ostringstream sout;

    SUBCASE("Test with 111111111111111")
    {
        BigInt a("111111111111111");
        sout << a;
        REQUIRE(sout.str() == "111111111111111");
    }

    SUBCASE("Test with -111111111111111")
    {
        BigInt a("-111111111111111");
        sout << a;
        REQUIRE(sout.str() == "-111111111111111");
    }

    SUBCASE("Test with +123456789")
    {
        BigInt a("+123456789");
        sout << a;
        REQUIRE(sout.str() == "123456789");
    }

    SUBCASE("Test with 000011234")
    {
        BigInt a("000011234");
        sout << a;
        REQUIRE(sout.str() == "11234");
    }
}

TEST_CASE("bigInt: int constructor")
{
    ostringstream sout;

    SUBCASE("Test with -1000000000")
    {
        BigInt a(-1000000000);
        sout << a;
        REQUIRE(sout.str() == "-1000000000");
    }

    SUBCASE("Test with 100000000")
    {
        BigInt a(100000000);
        sout << a;
        REQUIRE(sout.str() == "100000000");
    }

    SUBCASE("Test with +123456789")
    {
        BigInt a(+123456789);
        sout << a;
        REQUIRE(sout.str() == "123456789");
    }

    SUBCASE("Test with 0123")
    {
        BigInt a(0123);
        sout << a;
        REQUIRE(sout.str() == "83");
    }
}

TEST_CASE("bigInt: intput operator >>")
{

    ostringstream sout;
    SUBCASE("Test with -1000000000")
    {
        istringstream sinp("-1000000000");
        BigInt a;
        sinp >> a;
        sout << a;
        REQUIRE(sout.str() == "-1000000000");
    }

    SUBCASE("Test with 100000000")
    {
        istringstream sinp("100000000");
        BigInt a;
        sinp >> a;
        sout << a;
        REQUIRE(sout.str() == "100000000");
    }

    SUBCASE("Test with +123456789")
    {
        istringstream sinp("+123456789");
        BigInt a;
        sinp >> a;
        sout << a;
        REQUIRE(sout.str() == "123456789");
    }

    SUBCASE("Test with 0123")
    {
        istringstream sinp("0123");
        BigInt a;
        sinp >> a;
        sout << a;
        REQUIRE(sout.str() == "123");
    }
}