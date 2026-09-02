#include <stdio.h>
#include "math.h"

int main() 
{
    int x = 7;
    int y = 20;
    int z = 4;

    printf("square of %d is %d\n", x, square(x));
    printf("%d divide %d is %d\n", y, z, divide(y, z));

    return 0;
}