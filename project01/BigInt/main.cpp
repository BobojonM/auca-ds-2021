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

TEST_CASE("bigInt: operator +")
{
    ostringstream sout;
    SUBCASE("Test with 123 + 11234")
    {
        BigInt a(123);
        BigInt b(11234);

        sout << a + b;

        REQUIRE(sout.str() == "11357");
    }

    SUBCASE("Test with 9999 + 1")
    {
        BigInt a(9999);
        BigInt b(1);

        sout << a + b;

        REQUIRE(sout.str() == "10000");
    }

    SUBCASE("Test with 9999 + 999")
    {
        BigInt a(9999);
        BigInt b(999);

        sout << a + b;

        REQUIRE(sout.str() == "10998");
    }

    SUBCASE("Test with 9999 + -9999")
    {
        BigInt a(9999);
        BigInt b(-9999);

        sout << a + b;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("Test with -1234 + 65")
    {
        BigInt a(-1234);
        BigInt b(65);

        sout << a + b;

        REQUIRE(sout.str() == "-1169");
    }

    SUBCASE("Test with 1234 + -65")
    {
        BigInt a(1234);
        BigInt b(-65);

        sout << a + b;

        REQUIRE(sout.str() == "1169");
    }

    SUBCASE("Test with 12 + -65")
    {
        BigInt a(1234);
        BigInt b(-65);

        sout << a + b;

        REQUIRE(sout.str() == "1169");
    }
}

TEST_CASE("bigInt: operator -")
{
    ostringstream sout;
    SUBCASE("Test with -1234 - -65")
    {
        BigInt a(-1234);
        BigInt b(-65);

        sout << a - b;

        REQUIRE(sout.str() == "-1169");
    }

    SUBCASE("Test with -1234 - 65")
    {
        BigInt a(-1234);
        BigInt b(65);

        sout << a - b;

        REQUIRE(sout.str() == "-1299");
    }

    SUBCASE("Test with 1234 - -65")
    {
        BigInt a(1234);
        BigInt b(-65);

        sout << a - b;

        REQUIRE(sout.str() == "1299");
    }

    SUBCASE("Test with 1234 - 65")
    {
        BigInt a(1234);
        BigInt b(65);

        sout << a - b;

        REQUIRE(sout.str() == "1169");
    }

    SUBCASE("Test with 123 - 123")
    {
        BigInt a(123);
        BigInt b(123);

        sout << a - b;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("Test with 12 - 65")
    {
        BigInt a(12);
        BigInt b(65);

        sout << a - b;

        REQUIRE(sout.str() == "-53");
    }
}

TEST_CASE("bigInt: operator >")
{
    ostringstream sout;
    SUBCASE("Test with -1234 > -65")
    {
        BigInt a(-1234);
        BigInt b(-65);

        REQUIRE((a > b) == false);
    }

    SUBCASE("Test with 1 > -65")
    {
        BigInt a(1);
        BigInt b(-65);

        REQUIRE((a > b) == true);
    }

    SUBCASE("Test with -1 > 65")
    {
        BigInt a(-1);
        BigInt b(65);

        REQUIRE((a > b) == false);
    }

    SUBCASE("Test with 10 > 9")
    {
        BigInt a(10);
        BigInt b(9);

        REQUIRE((a > b) == true);
    }
}

TEST_CASE("bigInt: operator <")
{
    ostringstream sout;
    SUBCASE("Test with -1234 < -65")
    {
        BigInt a(-1234);
        BigInt b(-65);

        REQUIRE((a < b) == true);
    }

    SUBCASE("Test with 1 < -65")
    {
        BigInt a(1);
        BigInt b(-65);

        REQUIRE((a < b) == false);
    }

    SUBCASE("Test with -1 < 65")
    {
        BigInt a(-1);
        BigInt b(65);

        REQUIRE((a < b) == true);
    }

    SUBCASE("Test with 10 < 9")
    {
        BigInt a(10);
        BigInt b(9);

        REQUIRE((a < b) == false);
    }
}