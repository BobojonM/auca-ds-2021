#pragma once
#include <utility>

template <typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter beg, BidirectionalIter end)
{
    while (beg != end)
    {
        end--;
        if (beg == end)
            break;

        auSwap(*beg, *end);

        ++beg;
    }
}

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    while (beg != end)
    {
        if (*beg == key)
        {
            return beg;
        }

        beg++;
    }

    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate pred)
{
    while (beg != end)
    {
        if (pred(*beg))
        {
            return beg;
        }

        beg++;
    }

    return beg;
}

template <typename ForwardIter>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end)
{
    ForwardIter min = beg;
    while (beg != end)
    {
        if (*min > *beg)
        {
            min = beg;
        }

        beg++;
    }

    return min;
}