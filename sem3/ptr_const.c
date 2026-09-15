#include <stdio.h>

void check_int()
{
    int a = 1;
    int b = 2;

    // case 1
    int *pa = &a;
    // *pa = 2;
    // pa = &b;

    // case 2
    const int *pca = &a;
    // *pca = 3;
    // pca = &b;

    // case 3
    int* const cpa = &a;
    // *cpa = 4;
    // cpa = &b;

    // case 4
    const int* const cpca = &a;
    // *cpca = 4;
    // cpca = &b;
}

void check_const_int()
{
    const int b = 1;

    // case 1
    int *pb = &b;
    *pb = 2;
    printf("b = %d\n", b);

    // case 2
    const int *pcb = &b;
    // *pcb = 1;
    // printf("b = %d\n", b);

    // case 3
    int * const cpb = &b;
    // *cpb = 1;
    // printf("b = %d\n", b);

    // case 4
    const int* const cpcb = &b;
    // *cpcb = 1;
    // printf("b = %d\n", b);
}

int main()
{
    check_int();
    check_const_int();
}