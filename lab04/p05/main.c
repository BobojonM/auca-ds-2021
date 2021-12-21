#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end)
{
    for (; beg < end; beg++)
    {
        printf("%d ", *beg);
    }
    printf("\n");
}

void reverse(int *beg, int *end)
{
    int tmp;

    while (beg != end)
    {
        --end;
        if (beg == end)
            break;

        tmp = *beg;
        *beg = *end;
        *end = tmp;

        beg++;
    }
}

int main(void)
{
    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;

    int x;
    while (scanf("%d", &x) == 1)
    {
        if (sz == cp)
        {
            cp = cp == 0 ? 1 : 2 * cp;
            int *newData = (int *)malloc(cp * sizeof(int));
            for (size_t i = 0; i < sz; ++i)
            {
                newData[i] = data[i];
            }
            free(data);
            data = newData;
        }
        data[sz++] = x;
    }

    printArray(data, data + sz);
    reverse(data, data + sz);
    printArray(data, data + sz);

    free(data);
}