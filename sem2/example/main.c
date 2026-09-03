#include <stdio.h>
#include "math.h"

#define DEBUG_MESSAGE 1

#if DEBUG_MESSAGE
#define MESSAGE "debug"
#else
#define MESSAGE "release"
#endif

int main()
{
    int x = 7;
    int y = 20;
    int z = 4;

    printf("square of %d is %d\n", x, square(x));
    printf("%d divide %d is %d\n", y, z, divide(y, z));
    
    printf("%s\n", MESSAGE);

    return 0;
}