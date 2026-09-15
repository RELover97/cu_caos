#include <stdio.h>

int* fun()
{
    int d;
    return &d;
}

int* fun2()
{
    static int d;
    return &d;
}

int main()
{
    int *a = NULL;
    int *b;
    int *c;
    {
        int d = 10;
        c = &d;
    }


    // All the cases below are UB!
    printf("%d\n", *a);
    printf("%d\n", *b);
    printf("%d\n", *c);
    printf("%p\n", fun());
    // This case is ok!
    printf("%p\n", fun2());
}