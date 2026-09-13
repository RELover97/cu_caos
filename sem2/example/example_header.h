// макросы условной компиляции
#ifndef EXAMPLE_H
#define EXAMPLE_H
// другой вариант:
// #pragma once

typedef unsigned long long key_t;    // определяем key_t как беззнаковый 64-битный целый тип

enum Flags { OPEN = 1, WRITE = 2 };  // перечислимый тип enum Flags и константы OPEN, WRITE

struct Node                          // определение структурного типа struct Node
{
	struct Node *next;
	key_t key;
};

struct Handle;                       // объявление структурного типа struct Handle (пример непрозрачной структуры / opaque struct)
typedef struct Handle *handle_t;     // определение handle_t как типа указателя на struct Handle

extern int counter; // объявление глобальной нестатической переменной, которая определена в каком-то одном файле реализации

void function(int); // объявление функции

// встраиваемая функция
inline long long maxll(long long a, long long b) {
	return a>=b?a:b;
}

// макросы
#define PI 3.14
#define SUM(a, b) ((a) + (b))
#define TOSTR(a) #a
#define GLUE(a, b) a##b

// сбросить ранее определённый макрос
#undef PI

#endif