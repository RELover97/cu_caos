#include <stdlib.h>

int main(void) 
{
    char *s = malloc(10);

    if (s == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i <= 10; ++i) {
        s[i] = 'a';
    }

    free(s);

    return EXIT_SUCCESS;
}