#include <stdio.h>
#include "math.h"

#define DEBUG_MESSAGE 1

#if DEBUG_MESSAGE
#define MESSAGE "debug"
#else
#define MESSAGE "release"
#endif

double global_init_var = 1;
float global_var;

static int static_global_var = 2;

int main()
{
    int x = 7;
    int y = 20;
    int z = 4;

    printf("square of %d is %d\n", x, square(x));
    printf("%d divide %d is %d\n", y, z, divide(y, z));
    
    printf("%s\n", MESSAGE);

    static int static_local_var = 3;

    return 0;
}