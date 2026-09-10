#include <stdio.h>

int main()
{
    int x = 10;
    x += 5; 
    printf("x += 5 -> x=%d\n", x); // x=15
    x -= 3; 
    printf("x -= 3 -> x=%d\n", x); // x=12
    x *= 2; 
    printf("x *= 2 -> x=%d\n", x); // x=24
    x /= 4; 
    printf("x /= 4 -> x=%d\n", x); // x=6
    int result = 2 + 3 * 4; // 14, а не 20
    int result2 = (2 + 3) * 4; // 20 — скобки меняют порядок
    printf("Приоритет: %d, %d\n", result, result2);
}