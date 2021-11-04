#pragma once
#include <utility>

template <typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}