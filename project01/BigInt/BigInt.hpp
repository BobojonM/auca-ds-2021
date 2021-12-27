#pragma once

#include <vector>
#include <iosfwd>
#include <string>
#include <cstdint>
#include <iostream>
#include <algorithm>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

template <typename C>
bool compare(C a, C b)
{
    int res = 1, i = 0, j = 0;

    if (sz(a) > sz(b))
    {
        return res;
    }
    if (sz(a) < sz(b))
    {
        return 0;
    }

    for (; i < sz(a) && j < sz(b); i++, j++)
    {
        if (a[i] < b[i])
        {
            res = 0;
            break;
        }
    }
    return res;
}

class BigInt
{
    std::vector<int> mDigits;
    int mIsNegative;

    friend BigInt operator+(const BigInt &a, const BigInt &b);
    friend BigInt operator-(const BigInt &a, const BigInt &b);
    friend BigInt operator*(const BigInt &a, const BigInt &b);
    friend BigInt operator%(const BigInt &a, const BigInt &b);
    friend BigInt operator/(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend BigInt abs(const BigInt &a);

    static BigInt add(const BigInt &a, const BigInt &b)
    {
        auto i = a.mDigits.rbegin();
        auto j = b.mDigits.rbegin();

        std::string res = "";

        int carry = 0;
        while (i != a.mDigits.rend() || j != b.mDigits.rend())
        {
            int sum = carry;
            if (i != a.mDigits.rend())
            {
                sum += (*i * a.mIsNegative);
                i++;
            }
            if (j != b.mDigits.rend())
            {
                sum += (*j * b.mIsNegative);
                j++;
            }
            if (sum < 0)
            {
                sum += 10;
                carry = -1;
                res += std::to_string(sum % 10);
                continue;
            }
            else
            {
                carry = sum / 10;
                res += std::to_string(sum % 10);
            }
        }
        if (carry)
        {
            res += std::to_string(carry);
        }
        std::reverse(res.begin(), res.end());

        return BigInt(res);
    }

public:
    BigInt()
        : mIsNegative(1)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &n)
        : mIsNegative(1)
    {
        parseString(n);
    }

    BigInt(const long long &n)
        : mIsNegative(1)
    {
        parseString(std::to_string(n));
    }

    const std::vector<int> &digits() const
    {
        return mDigits;
    }

    bool isNegative() const
    {
        return (mIsNegative == -1 ? true : false);
    }

    int size() const
    {
        return mDigits.size();
    }

    void parseString(const std::string &m)
    {
        if (m.empty())
        {
            throw std::runtime_error("Incorrect input ");
        }

        //bool neg = false;
        std::string n = m;
        if (n[0] == '+' || n[0] == '-')
        {
            mIsNegative = (n[0] == '-' ? -1 : 1);
            //std::cout << mIsNegative << "\n";
            n = n.substr(1);
        }

        for (char ch : n)
        {
            if (!isdigit(ch))
            {
                throw std::runtime_error("Incorrect input ");
            }
            else
            {
                mDigits.push_back(ch - '0');
            }
        }

        for (int i = 0; mDigits[i] == 0 && mDigits.size() > 1;)
        {
            mDigits.erase(mDigits.begin() + i);
        }

        //mIsNegative = neg;
    }
};

BigInt mul(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    std::vector<int> rDigits(al + bl);

    for (int i = 1; i <= al; i++)
    {
        int d = 0;
        for (int j = 1; j <= bl; j++)
        {
            int mul = aDigits[al - i] * bDigits[bl - j];
            int oldr = rDigits[(j - 1) + (i - 1)];
            rDigits[(j - 1) + (i - 1)] = (oldr + mul + d) % 10;
            //std::cout << d << "\n";
            d = (oldr + mul + d) / 10;
            //std::cout << rDigits[(j - 1) + (i - 1)] << " " << d << "\n";
        }

        if (d)
            rDigits[bl + (i - 1)] = (rDigits[bl + (i - 1)] + d) % 10;
    }

    std::string sout;
    for (int i = rDigits.size() - 1; i > -1; i--)
    {
        sout += std::to_string(rDigits[i]);
    }

    //std::cout << sout.str() << "\n";
    //std::cout << "\n";
    return BigInt(sout);
}

bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative < b.mIsNegative)
    {
        return 1;
    }
    else if (a.mIsNegative > b.mIsNegative)
    {
        return 0;
    }

    if (a.mIsNegative == 1 && b.mIsNegative == 1)
    {
        if (sz(a.mDigits) < sz(b.mDigits))
        {
            return 1;
        }
        else if (sz(a.mDigits) > sz(b.mDigits))
        {
            return 0;
        }
    }

    if (a.mIsNegative == -1 && b.mIsNegative == -1)
    {
        if (sz(a.mDigits) < sz(b.mDigits))
        {
            return 0;
        }
        else if (sz(a.mDigits) > sz(b.mDigits))
        {
            return 1;
        }
    }

    for (int i = 0; i < sz(a.mDigits) && i < sz(b.mDigits); i++)
    {
        if (a.mDigits[i] != b.mDigits[i])
        {
            if (a.mIsNegative == 1 && b.mIsNegative == 1)
            {
                return a.mDigits[i] < b.mDigits[i];
            }
            else
            {
                return !(a.mDigits[i] < b.mDigits[i]);
            }
        }
    }
    return 0;
}
bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}

bool operator==(const BigInt &a, const BigInt &b)
{
    return (!(a < b) && !(b < a));
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

bool operator<=(const BigInt &a, const BigInt &b)
{
    return (a < b || a == b);
}

bool operator>=(const BigInt &a, const BigInt &b)
{
    return (b < a || b == a);
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative == b.mIsNegative)
    {
        BigInt a1 = a;
        BigInt b1 = b;
        a1.mIsNegative = 1;
        b1.mIsNegative = 1;

        BigInt temp = a1.add(a1, b1);
        temp.mIsNegative = a.mIsNegative;

        return temp;
    }
    else
    {
        BigInt a1 = a;
        BigInt b1 = b;
        if (!(a.mIsNegative == 1 && b.mIsNegative == -1))
        {
            a1 = b;
            b1 = a;
        }

        if (compare(a1.mDigits, b1.mDigits))
        {
            return a.add(a1, b1);
        }
        else
        {
            BigInt tempA = a1;
            BigInt tempB = b1;

            tempA.mIsNegative = b1.mIsNegative;
            tempB.mIsNegative = a1.mIsNegative;

            BigInt res = a1.add(tempB, tempA);
            res.mIsNegative = res.mIsNegative * (-1);

            return res;
        }
    }
}
BigInt abs(const BigInt &a)
{
    BigInt absA = a;
    absA.mIsNegative = 1;
    return absA;
}

BigInt operator-(const BigInt &a, const BigInt &b)
{
    BigInt b1 = b;
    b1.mIsNegative = -b1.mIsNegative;

    return (a + b1);
}

void operator+=(BigInt &a, const BigInt &b)
{
    a = a + b;
}

void operator-=(BigInt &a, const BigInt &b)
{
    a = a - b;
}

std::istream &operator>>(std::istream &sinp, BigInt &b)
{
    std::string str, line;

    while (getline(sinp, line))
    {
        str += line;
    }

    b = BigInt(str);

    return sinp;
}

std::ostream &operator<<(std::ostream &sout, const BigInt &b)
{
    if (b.isNegative())
    {
        sout << "-";
    }

    for (int digit : b.digits())
    {
        sout << digit;
    }

    return sout;
}

BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt r;

    int al = a.size();
    int bl = b.size();

    r = mul(a.digits(), al, b.digits(), bl);

    if ((a.isNegative() || b.isNegative()) && !(a.isNegative() && b.isNegative()))
    {
        if (b != BigInt(0) && a != BigInt(0))
            r.mIsNegative = -1;
        //r.setSighn(true);
    }

    return r;
}

BigInt operator/(const BigInt &a, const BigInt &b)
{
    std::string value = "";
    std::string res = "0";

    BigInt div = b;
    div.mIsNegative = 1;

    if (div.mDigits[0] == 0)
        throw std::runtime_error("Devision by zero");

    int ind = 0, end = sz(a.mDigits);
    for (; ind < end && ind < sz(b.mDigits); ind++)
        value += std::to_string(a.mDigits[ind]);

    ind--;
    while (ind < end)
    {
        BigInt temp(value);

        int q = 0;
        while (temp >= div)
        {
            temp -= div;
            q++;
        }
        res += std::to_string(q);

        value = "";
        for (int j = 0; j < sz(temp.mDigits); j++)
            value += std::to_string(temp.mDigits[j]);

        ind++;
        if (ind < end)
            value += std::to_string(a.mDigits[ind]);
    }

    BigInt result(res);

    if (a.mIsNegative != b.mIsNegative)
        result.mIsNegative = -1;

    return result;
}

BigInt operator%(const BigInt &a, const BigInt &b)
{

    return a - ((a / b) * b);
}

void operator/=(BigInt &a, const BigInt &b)
{
    a = a / b;
}

void operator*=(BigInt &a, const BigInt &b)
{
    a = a * b;
}

void operator%=(BigInt &a, const BigInt &b)
{
    a = a % b;
}