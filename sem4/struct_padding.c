#include <stddef.h>
#include <stdio.h>

struct Example {
    char c;
    int i;
    double d;
};

int main(void) {
    printf("sizeof(char)   = %zu\n", sizeof(char));
    printf("sizeof(int)    = %zu\n", sizeof(int));
    printf("sizeof(double) = %zu\n", sizeof(double));

    printf("\n");

    printf("sizeof(struct Example) = %zu\n",
           sizeof(struct Example));

    printf("_Alignof(char) = %zu\n",
           _Alignof(char));

    printf("_Alignof(int) = %zu\n",
           _Alignof(int));

    printf("_Alignof(double) = %zu\n",
           _Alignof(double));

    printf("_Alignof(struct Example) = %zu\n",
           _Alignof(struct Example));

    printf("\n");

    printf("offset(c) = %zu\n",
           offsetof(struct Example, c));

    printf("offset(i) = %zu\n",
           offsetof(struct Example, i));

    printf("offset(d) = %zu\n",
           offsetof(struct Example, d));

    return 0;
}