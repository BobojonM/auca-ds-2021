#include <stdio.h>

int main()
{
    int x;
    int y;
    int *p;

    x = 1;
    p = &x;

    printf("value of x: %d\n", x);
    printf("adress of x: %p\n", p);
    printf("value of x: %d\n", *p);

    *p = 2;

    printf("value of x: %d\n", x);
    printf("value of x: %d\n", *p);

    y = *p * *p;

    printf("value of y: %d\n", y);
}