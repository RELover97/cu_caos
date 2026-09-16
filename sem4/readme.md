# Динамическая память в языке С. Структуры и объединения

Будем делать мини-проект хранилища событий журнала приложений: мы хотим строки журнала приложения вида:
```
LOGIN alice
ERROR 42 connection_lost
PURCHASE 123 1990
LOGIN bob
ERROR 17 timeout
```

## Первая версия

В чём проблема?

- максимальная длина строки фиксирована;
- длинная строка будет обрезана;
- пока мы не знаем, сколько строк будет вообще.

## Строка произвольной длины

Напишем отдельную функцию, которая будет считывать строку проивзольной длины и возвращать указатель на неё в динамической памяти:
```
char* read_line(void);
```

Функция должна:

- читать до `\n`

- читать строку любой длины

- возвращать корректную строку с точки зрения С

- вернуть `NULL` на EOF

Типичные функции работы с динамической памятью в языке С:
```
void* malloc(size_t size);
```
```
void *calloc(size_t nelem, size_t size);
```
Тут проверяется, что `nelem` * `size` не переполнит `size_t`.

```
void *realloc(void *oldptr, size_t newsize);
```
Если невохможно перевыделить память, то вернёт `NULL`, а "старая" память сохранится. Если `oldptr == NULL`, то работает как `malloc`. Если `newsize == 0`, то зависит от реализации: или как `free`, или `malloc(0)`.
```
void free(void *ptr);
```
Корректно работает для `ptr == NULL`
```
void *reallocarray(void *oldptr, size_t nelem, size_t size);
```
Как `realloc`, только проверяется `nelem` * `size` на перепонение `size_t`

Всё ли хорошо с текущей реализацией `read_line`?

- не забывать проверять возвращаемое значение функций работы с динамической памятью

- если что-то не так, то не забывать освободить уже аллоцированную память

- C -строка должна заканчиваться `\0`

- `EOF` не представим в `char`!

## Как хранить любое число строк произвольной длины

Напишем свой динамический вектор строк. 

Всё ли в порядке в текущем коде и что написать надо после комментария?

- Для освобождения двумерного динамического массива сперва надо освободить память каждого одномерного массива, а затем уже память под указатели на эти одномерные массивы

- В случае реаллокации памяти под двумерный массив нужно реалоцировать память только под указатели на одномерные массивы и не забыть проверить возвращаемое значение

## Как искать ошибки работы с памятью?

В чём проблема в `heap_case_1.c`?

Как найти ошибку:
```
gcc -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer heap_case_1.c
./a.out
```

В чём проблема в `heap_case_2.c`?

```
gcc -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer heap_case_2.c
./a.out
```

В чём проблема в `heap_case_3.c`?
```
gcc -g -O1 -fsanitize=address,leak -fno-omit-frame-pointer heap_case_3.c
./a.out
```

## Вырванивания и отступы в структурах

## Объединения

Ещё раз посмотрим на возможное содержимое журнала:
```
LOGIN alice
ERROR 42 connection_lost
PURCHASE 123 1990
LOGIN bob
ERROR 17 timeout
```

У нас есть разные виды событий:
- LOGIN
- ERROR
- PURCHASE

При этом у каждого вида событий есть свои данные:
- LOGIN: имя пользователя
- ERROR: сообщение об ошибке и код
- PURCHASE: ID продукта и цена

Как наивно можно хранить эти данные:
```
struct EventBad {
    int type;

    char *username;

    int error_code;
    char *error_message;

    int product_id;
    int price;
};
```

Но это расточительно по памяти. Решение - `union`:
```
enum EventType {
    EVENT_NONE = 0,
    EVENT_LOGIN,
    EVENT_ERROR,
    EVENT_PURCHASE
};

struct Event {
    uint64_t timestamp;
    enum EventType type;

    union {
        struct {
            char *username;
        } login;

        struct {
            int code;
            char *message;
        } error;

        struct {
            int product_id;
            int price;
        } purchase;
    } data;
};
```