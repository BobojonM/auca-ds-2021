#pragma once

#include <vector>
#include <iosfwd>

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

    const std::vector<int> &digits() const
    {
        return mDigits;
    }

    const bool &isNegative() const
    {
        return mIsNegative;
    }
};

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