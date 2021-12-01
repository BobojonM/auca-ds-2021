#pragma once

#include <vector>
#include <iosfwd>
#include <string>

class BigInt
{
    friend BigInt operator+(const BigInt &a, const BigInt &b);
    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &n)
        : mIsNegative(false)
    {
        parseString(n);
    }

    BigInt(const long long &n)
        : mIsNegative(false)
    {
        parseString(std::to_string(n));
    }

    const std::vector<int> &digits() const
    {
        return mDigits;
    }

    const bool &isNegative() const
    {
        return mIsNegative;
    }

    void parseString(const std::string &m)
    {
        if (m.empty())
        {
            throw std::runtime_error("Incorrect input ");
        }

        std::string n = m;
        if (n[0] == '+' || n[0] == '-')
        {
            mIsNegative = (n[0] == '-' ? true : false);
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

        for (int i = 0; mDigits[i] == 0;)
        {
            mDigits.erase(mDigits.begin() + i);
        }
    }
};

BigInt add(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    std::vector<int> rDigits;

    int d = 0;
    for (int i = 1; i <= al; i++)
    {
        int sum = aDigits[al - i] + bDigits[bl - i];
        rDigits.push_back((sum + d) % 10);
        d = (sum + d) / 10;
    }

    int d2 = 0;
    for (int i = bl + 1; i <= al; i++)
    {
        int sum = aDigits[al - i] + d;
        rDigits.push_back((sum + d2) % 10);
        d2 = (sum + d2) / 10;
        d = 0;
    }

    rDigits.push_back(d2);

    std::ostringstream sout;
    for (int i = rDigits.size() - 1; i > -1; i--)
    {
        sout << rDigits[i];
    }

    return BigInt(sout.str());
}

BigInt sub(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    std::vector<int> rDigits;

    int d = 0;
    for (int i = 1; i <= al; i++)
    {
        int sum = (aDigits[al - i] - d) - bDigits[bl - i];
        d = 0;
        if (sum < 0)
        {
            d = -1;
            sum = 10 - sum;
        }
        rDigits.push_back(sum);
    }

    int d2 = 0;
    for (int i = bl + 1; i <= al; i++)
    {
        int sum = aDigits[al - i] - d;
        d2 = 0;
        if (sum < 0)
        {
            d2 = -1;
            sum = 10 - sum;
        }
        rDigits.push_back(sum);
        d = 0;
    }

    std::ostringstream sout;
    for (int i = rDigits.size() - 1; i > -1; i--)
    {
        sout << rDigits[i];
    }

    return BigInt(sout.str());
}

bool bigger(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    if (al > bl)
        return true;
    else if (al < bl)
        return false;
    else
    {
        int i = std::max(al, bl);
        while (i > 0)
        {
            if (aDigits[i - 1] > bDigits[i - 1])
                return true;
            else if (aDigits[i - 1] < bDigits[i - 1])
                return false;
            i--;
        }
    }

    return true;
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt r;

    int al = a.digits().size();
    int bl = b.digits().size();

    if (bigger(a.digits(), al, b.digits(), bl))
    {
        if (a.isNegative() and b.isNegative())
        {
            r = add(a.digits(), al, b.digits(), bl);
        }
        else if (a.isNegative() || b.isNegative())
        {
            r = sub(a.digits(), al, b.digits(), bl);
            if (a.isNegative())
                r.mIsNegative = true;
        }
        else
            r = add(a.digits(), al, b.digits(), bl);
    }
    else
    {
        if (b.isNegative() and a.isNegative())
        {
            r = add(b.digits(), bl, a.digits(), al);
        }
        else if (b.isNegative() || a.isNegative())
        {
            r = sub(b.digits(), bl, a.digits(), al);
            if (b.isNegative())
                r.mIsNegative = true;
        }
        else
            r = add(b.digits(), bl, a.digits(), al);
    }

    return r;
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