#include "VecInt.h"
#include <stdio.h>

void reverse(int *beg, int *end)
{
    while (beg != end)
    {
        end--;
        if (beg == end)
            break;

        int tmp = *beg;
        *beg = *end;
        *end = tmp;

        beg++;
    }
}

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf("%d ", *beg);
        beg++;
    }
    printf("\n");
}

void p01()
{
    struct VecInt v;
    int size;
    scanf("%d", &size);

    VecInt_createOfSize(&v, size, 0);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &v.data[i]);
    }

    printArray(v.data, v.data + size);
    reverse(v.data, v.data + size);
    printArray(v.data, v.data + size);

    VecInt_destroy(&v);
}

void p02()
{
    struct VecInt v;

    VecInt_createEmpty(&v);

    int x;
    while (scanf("%d", &x) == 1)
    {
        VecInt_pushBack(&v, x);
    }

    printArray(v.data, v.data + v.sz);
    reverse(v.data, v.data + v.sz);
    printArray(v.data, v.data + v.sz);

    VecInt_destroy(&v);
}

int main(void)
{
    p01();
    //p02();
}
