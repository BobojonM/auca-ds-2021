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