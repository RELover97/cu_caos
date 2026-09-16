#include <stdlib.h>
#include <string.h>

int main(void) 
{
    char *s = malloc(100);

    if (s == NULL) {
        return EXIT_FAILURE;
    }

    strcpy(s, "hello");

    return 0;
}