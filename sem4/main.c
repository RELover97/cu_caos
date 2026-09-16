#include <stdio.h>

#define MAX_LINE 32

int main(void) 
{
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), stdin)) {
        printf("%s", line);
    }

    return 0;
}