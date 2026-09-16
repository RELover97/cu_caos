#include <stdio.h>
#include <stdlib.h>

// !
char* read_line(void) 
{
    size_t capacity = 16;
    size_t size = 0;

    char* buffer = malloc(capacity);

    while (1) {
        char c = getchar();

        if (c == '\n') {
            break;
        }

        if (size + 1 >= capacity) {
            size_t new_capacity = capacity * 2;

            char *tmp = realloc(buffer, new_capacity);

            buffer = tmp;
            capacity = new_capacity;
        }

        buffer[size++] = c;
    }

    if (size == 0 && feof(stdin)) {
        return NULL;
    }

    return buffer;
}


int main(void) 
{
    while (1) {
        char *line = read_line();

        if (line == NULL) {
            break;
        }

        printf("Read \"%s\"\n", line);

        free(line);
    }

    return 0;
}