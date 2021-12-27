#pragma once

#include <vector>
#include <iosfwd>
#include <string>

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

BigInt add(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    std::vector<int> rDigits;

    int d = 0;
    for (int i = 1; i <= bl; i++)
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

    std::ostringstream sout;
    for (int i = rDigits.size() - 1; i > -1; i--)
    {
        sout << rDigits[i];
    }

    //std::cout << sout.str() << "\n";
    //std::cout << "\n";
    return BigInt(sout.str());
}

BigInt sub(std::vector<int> aDigits, int al, std::vector<int> bDigits, int bl)
{
    std::vector<int> rDigits;

    int d = 0;
    for (int i = 1; i <= bl; i++)
    {
        int sum = (aDigits[al - i] + d) - bDigits[bl - i];
        d = 0;
        if (sum < 0)
        {
            d = -1;
            sum = 10 + sum;
        }
        rDigits.push_back(sum);
    }

    int d2 = 0;
    for (int i = bl + 1; i <= al; i++)
    {
        int sum = aDigits[al - i] + d + d2;
        d2 = 0;
        if (sum < 0)
        {
            d2 = -1;
            sum = 10 + sum;
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

bool bigger(const BigInt a, int al, const BigInt b, int bl)
{
    std::vector<int> aDigits = a.digits();
    std::vector<int> bDigits = b.digits();

    if (al > bl)
        return true;
    else if (al < bl)
        return false;
    else
    {
        int i = al;
        while (i > 0)
        {
            if (aDigits[i - 1] > bDigits[i - 1])
                return true;
            else if (aDigits[i - 1] < bDigits[i - 1])
                return false;
            i--;
        }

        if (a.isNegative())
            return false;
    }

    return true;
}

BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt r;
    int al = a.size();
    int bl = b.size();
    if (bigger(a, al, b, bl))
    {
        if (a.isNegative() and b.isNegative())
        {
            r = add(a.digits(), al, b.digits(), bl);
        }
        else if (a.isNegative() || b.isNegative())
        {
            r = sub(a.digits(), al, b.digits(), bl);
            if (a.isNegative())
            {
                r.mIsNegative = -1;
                //r.setSighn(true);
            }
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
            {
                r.mIsNegative = -1;
                //r.setSighn(true);
            }
        }
        else
        {
            r = add(b.digits(), bl, a.digits(), al);
        }
    }
    return r;
}

BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt r;

    int al = a.size();
    int bl = b.size();

    r = mul(a.digits(), al, b.digits(), bl);

    if ((a.isNegative() || b.isNegative()) && !(a.isNegative() && b.isNegative()))
    {
        r.mIsNegative = -1;
        //r.setSighn(true);
    }

    return r;
}

BigInt operator-(const BigInt &a, const BigInt &b)
{
    BigInt r;
    int al = a.size();
    int bl = b.size();
    if (bigger(a, al, b, bl))
    {
        if (a.isNegative() and b.isNegative())
        {
            r = sub(a.digits(), al, b.digits(), bl);
            r.mIsNegative = -1;
            //r.setSighn(true);
        }
        else if (a.isNegative() || b.isNegative())
        {
            r = add(a.digits(), al, b.digits(), bl);
            if (a.isNegative())
            {
                r.mIsNegative = -1;
                //r.setSighn(true);
            }
        }
        else
            r = sub(a.digits(), al, b.digits(), bl);
    }
    else
    {
        if (b.isNegative() and a.isNegative())
        {
            r = sub(b.digits(), bl, a.digits(), al);
            r.mIsNegative = -1;
            //r.setSighn(true);
        }
        else if (b.isNegative() || a.isNegative())
        {
            r = add(b.digits(), bl, a.digits(), al);
            if (b.isNegative())
            {
                r.mIsNegative = -1;
                //r.setSighn(true);
            }
        }
        else
        {
            r = sub(b.digits(), bl, a.digits(), al);
            r.mIsNegative = -1;
            //r.setSighn(true);
        }
    }

    return r;
}

bool operator==(const BigInt &a, const BigInt &b)
{
    if (a.isNegative() == b.isNegative() && a.size() == b.size())
    {
        std::vector<int> aDigits = a.digits();
        std::vector<int> bDigits = b.digits();
        for (int i = 0; i < a.size(); i++)
        {
            if (aDigits[i] != bDigits[i])
                return false;
        }
        return true;
    }

    return false;
}

// bool operator>(const BigInt &a, const BigInt &b)
// {
//     if (!a.isNegative() && b.isNegative())
//         return true;
//     else if (a.isNegative() && !b.isNegative())
//         return false;
//     else if (a.isNegative() && b.isNegative())
//         return !bigger(a, a.size(), b, b.size());
//     return (bigger(a, a.size(), b, b.size()) && !(a == b));
// }

// bool operator<(const BigInt &a, const BigInt &b)
// {
//     if (!a.isNegative() && b.isNegative())
//         return false;
//     else if (a.isNegative() && !b.isNegative())
//         return true;
//     else if (a.isNegative() && b.isNegative())
//         return bigger(a, a.size(), b, b.size());
//     return !bigger(a, a.size(), b, b.size());
// }

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

bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}

bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(a > b);
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

// BigInt operator%(const BigInt &a, const BigInt &b)
// {
//     BigInt r = a - ((a / b) * b);

//     if (a.isNegative())
//     {
//         r.setSighn(true);
//     }

//     return r;
// }

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

void operator+=(BigInt &a, const BigInt &b)
{
    a = a + b;
}

void operator-=(BigInt &a, const BigInt &b)
{
    a = a - b;
}

BigInt operator/(const BigInt &a, const BigInt &b)
{
    std::string value = "", ans = "0";

    BigInt divisor = b;
    divisor.mIsNegative = false;
    if (a.mIsNegative || b.mIsNegative)
        divisor.mIsNegative = true;
    if (a.mIsNegative == b.mIsNegative)
        divisor.mIsNegative = false;

    if (divisor.mDigits[0] == 0)
    {
        throw std::runtime_error("Devision by zero");
    }
    if (divisor.size() == 1)
    {
        if (divisor.mDigits[0] == 1)
        {
            BigInt res = a;
            res.mIsNegative = divisor.mIsNegative;
            return res;
        }

        //throw std::runtime_error("Devision by zero");
    }
    if (a == b)
    {
        BigInt res(1);
        res.mIsNegative = divisor.mIsNegative;
        return res;

        //throw std::runtime_error("Devision by zero");
    }

    int i = 0, end = sz(a.mDigits);
    for (; i < end && i < sz(b.mDigits); i++)
    {
        value += std::to_string(a.mDigits[i]);
    }
    --i;
    while (i < end)
    {
        BigInt temp(value);

        int q = 0;
        while (temp >= divisor)
        {
            temp -= divisor;
            q++;
        }
        ans += std::to_string(q);

        value = "";
        for (int j = 0; j < sz(temp.mDigits); j++)
        {
            value += std::to_string(temp.mDigits[j]);
        }
        ++i;
        if (i < end)
            value += std::to_string(a.mDigits[i]);
    }

    BigInt result(ans);

    result.mIsNegative = divisor.mIsNegative;
    return result;
}