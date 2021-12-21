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
    printf("the size of array: ");

    int n;
    scanf("%d", &n);

    int *dynArray = (int *)malloc(n * sizeof(int));
    if (dynArray == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dynArray[i]);
    }

    printArray(dynArray, dynArray + n);

    reverse(dynArray, dynArray + n);

    printArray(dynArray, dynArray + n);

    free(dynArray);
}