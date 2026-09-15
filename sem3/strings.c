/*
    Задача

    Написать программу, которая:
    - считывает с клавиатуры строку;
    - удаляет из неё завершающий '\n';
    - заменяет первое вхождение cat на dog, а в конце дописывает bird;
    - печатает строку, исходную или модифицированную, вместе с длиной;
    - разбивает строку на слова и выводит их вместе с количеством слов. 
*/

#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <stdbool.h>
#include <assert.h>

enum {
    LINE_MAX_LEN = 20 //maximum text length
};


bool remove_new_line_char(char *str, size_t len)
{
    if (len == 0) {
        return false;
    }

    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        return true;
    } else {
        return false;
    }
}

// When calling this function, it is guaranteed
// that EOF will not be meat
void remove_chars_till_line_end()
{
    int c;
    while ((c = getchar()) != '\n' && (c != EOF)) {
        printf("here");
    }
}

void print_words(char *line, size_t len)
{
    if (len == 0) {
        return;
    }
    // strtok changes line so we save the source line
    char words[len];
    strcpy(words, line);

    size_t word_count = 0;

    const char words_delimiters[] = " \t,.;:!?";

    char *token = strtok(words, words_delimiters);

    printf("\nWords:\n");

    while (token != NULL) {
        printf("  %s\n", token);

        ++word_count;

        // NULL means continue parse the same line
        token = strtok(NULL, words_delimiters);
    }

    printf("Number of words: %zu\n", word_count);
}


void process_lines()
{
    char line[LINE_MAX_LEN];

    char word_to_search[] = "cat";
    char word_to_replace[] = "dog";
    assert(strlen(word_to_search) == strlen(word_to_replace));

    char word_to_add[] = "bird";

    // read bytes either till '\n' is meat or (LINE_MAX_LEN - 1) bytes are read;
    // if '\n' is meat, it is put in the line;
    // if error, return NULL

    while (fgets(line, LINE_MAX_LEN, stdin) != NULL) {
        bool meat_new_line_char = remove_new_line_char(line, strlen(line));
        
        if (feof(stdin) == 0 && meat_new_line_char == false) {
            printf("Line read is too long, remove left chars from input\n");
            remove_chars_till_line_end();
        }

        printf("Read line of length %zu: %s\n", strlen(line), line);

        char *found = strstr(line, word_to_search);
        if (found) {
            char extended_str[strlen(line) + strlen(word_to_add) + 1]; // + 1 beacuse of '\0'
            strcpy(extended_str, line);
            // replace one word with another one
            strncpy(extended_str + (found - line), word_to_replace, sizeof(word_to_replace));
            strcpy(extended_str + (found - line) + strlen(word_to_replace), 
                    found + strlen(word_to_search));
            // add suffix to the word
            strncat(extended_str, word_to_add, sizeof(word_to_add));
            printf("New line of size %zu after replacement and concatenation: %s", strlen(extended_str), extended_str);

            print_words(extended_str, strlen(extended_str));
        } else {
            print_words(line, strlen(line));
        }
    }

    if (ferror(stdin)) {
        fprintf(stderr, "Error in input text!");
        exit(1);
    }
}

int main(void)
{
    process_lines();

    return 0;
}