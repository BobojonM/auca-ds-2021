#pragma once

#include <vector>
#include <iosfwd>
#include <string>

class BigInt
{
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

BigInt &operator+(BigInt &a, const BigInt &b)
{
    std::vector<int> rDigits;

    int al = a.digits().size();
    int bl = b.digits().size();
    std::vector<int> aDigits = a.digits();
    std::vector<int> bDigits = b.digits();

    std::vector<int> maxDigits = al > bl ? aDigits : bDigits;

    int d = 0;
    for (int i = 1; i <= std::min(al, bl); i++)
    {
        int sum = aDigits[al - i] + bDigits[al - i];
        rDigits.push_back((sum + d) % 10);
        d = (sum + d) / 10;
    }

    int ml = (int)maxDigits.size();
    int d2 = 0;
    for (int i = std::min(al, bl); i <= ml; i++)
    {
        int sum = maxDigits[ml - i] + d;
        rDigits.push_back((sum + d2) % 10);
        d2 = (sum + d2) / 10;
        d = 0;
    }

    std::ostringstream sout;
    for (int i : rDigits)
    {
        sout << i;
    }

    const std::string str(sout.str());

    return BigInt(str);
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