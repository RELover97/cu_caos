#include <stdio.h>
#include <stdlib.h>

// !
char* read_line(void) 
{
    size_t capacity = 16;
    size_t size = 0;

    char* buffer = malloc(capacity);
    // do not forget to check return value!
    if (buffer == NULL) {
        return NULL;
    }

    while (1) {
        int c = getchar(); // EOF is not represented in char!

        // c == EOF -> break endless loop
        if (c == EOF || c == '\n') {
            break;
        }

        if (size + 1 >= capacity) {
            size_t new_capacity = capacity * 2;

            char *tmp = realloc(buffer, new_capacity);

            // check return value!
            if (tmp == NULL) {
                free(buffer); // if something wrong, free allocated memmory
                return NULL;
            }

            buffer = tmp;
            capacity = new_capacity;
        }

        buffer[size++] = (char) c;
    }

    // C string must finish '\0'
    buffer[size] = '\0';

    if (size == 0 && feof(stdin)) {
        free(buffer); // free allocated memory if something wronh
        return NULL;
    }

    return buffer;
}

// Dynamic string vector

struct StringVector {
    char* *data;
    size_t size;
    size_t capacity;
};

void string_vector_init(struct StringVector *v) 
{
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// !
void string_vector_destroy(struct StringVector *v) 
{
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// !
// return 1 if successful, 0 otherwise
int string_vector_reserve(struct StringVector *v, size_t new_capacity) 
{
    if (new_capacity <= v->capacity) {
        return 1;
    }

    // write code here
}

int string_vector_push(struct StringVector *v, char *string) 
{
    if (v->size == v->capacity) {
        size_t new_capacity =
            v->capacity == 0
                ? 4
                : v->capacity * 2;

        if (!string_vector_reserve(v, new_capacity)) {
            return 0;
        }
    }

    v->data[v->size++] = string;

    return 1;
}

void string_vector_print(const struct StringVector *v) 
{
    for (size_t i = 0; i < v->size; ++i) {
        printf("%zu: %s\n", i, v->data[i]);
    }
}


enum {
    EXIT_SUCCESS,
    EXIT_FAILURE
};


int main(void) 
{
    struct StringVector lines;

    string_vector_init(&lines);

    while (1) {
        char *line = read_line();

        if (line == NULL) {
            break;
        }

        if (!string_vector_push(&lines, line)) {
            free(line);
            fprintf(stderr, "failed to append line\n");

            string_vector_destroy(&lines);

            return EXIT_FAILURE;
        }
    }

    printf("Stored lines:\n");
    string_vector_print(&lines);

    string_vector_destroy(&lines);

    return 0;
}