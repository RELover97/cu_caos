/*
    Задача. 
    На складе зафиксировали количество проданных товаров за 8 дней: {12, 7, 15, 9, 20, 7, 11, 18}

    Написать программу, которая:
    - хранит значения в обычном массиве int;
    - выводит каждый элемент вместе с его адресом в прямом и обратном порядке
    - вычисляет сумму и минимальный элемент;
    - ищет первое вхождение заданного значения и возвращает указатель на найденный элемент;
    - разворачивает массив на месте;
    - выводит результат.

    Всё хранится на стеке.
*/

#include <stdio.h>
#include <stddef.h> // size_t, ssize_t

enum { N = 8 };

// same as void print_array_forward_via_indices(const int a[], size_t n)
void print_array_forward_via_indices(const int *a, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        printf("a[%zu] is %d and has address %p\n", i, a[i], (void*) &a[i]);
    }
    printf("\n");
}


void print_array_forward_via_ptrs(const int a[], size_t n)
{
    const int * const a_end = a + n;
    for (const int *p = a; p != a_end; ++p) {
        ptrdiff_t i = p - a;
        printf("a[%zu] is %d and has address %p\n", i, *p, (void *) p);
    }
    printf("\n");
}


void print_array_backward_via_indices(const int *a, size_t n)
{
    for (size_t i = n; i > 0; --i) {
        printf("a[%zu] is %d and has address %p\n", i - 1, a[i - 1], (void*) &a[i - 1]);
    }
    printf("\n");
}


void print_array_backward_via_ptrs(const int a[], size_t n)
{
    const int *a_end = a + n;
    for (const int *p = a_end - 1; p >= a; --p) {
        ptrdiff_t i = p - a;
        printf("a[%zu] is %d and has address %p\n", i, *p, (void *)p);
    }
    printf("\n");
}


// !
long long sum_array(const int *a, size_t n)
{
    long long sum = 0;

    const int *p = a;
    const int *end = a + n;

    while (p != end) {
        sum += *p;
        ++p;
    }

    return sum;
}



const int *min_element(const int *a, size_t n)
{
    const int *min = a;
    const int *p = a + 1;
    const int *end = a + n;

    while (p != end) {
        if (*p < *min) {
            min = p;
        }

        ++p;
    }

    return min;
}



const int *find_value(const int *a, size_t n, int value)
{
    const int *p = a;
    const int *end = a + n;

    while (p != end) {
        if (*p == value) {
            return p;
        }

        ++p;
    }

    return NULL;
}



void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



void reverse_array(int *a, size_t n)
{
    if (n < 2) {
        return;
    }

    int *left = a;
    int *right = a + n - 1;

    while (left < right) {
        swap(left, right);

        ++left;
        --right;
    }
}



int main(void)
{
    // same as: sales[] = {};
    int sales[N] = {12, 7, 15, 9, 20, 7, 11, 18};

    printf("Input array:\n");
    print_array_forward_via_indices(sales, N);
    print_array_forward_via_ptrs(sales, N);
    print_array_backward_via_indices(sales, N);
    print_array_backward_via_ptrs(sales, N);

    int sum = sum_array(sales, N);

    const int *min = min_element(sales, N);

    printf("\nSum = %d\n", sum);
    printf("Minimum = %d\n", *min);
    printf("Minimum address = %p\n", (void *) min);

    int value = 7;

    const int *found = find_value(sales, N, value);

    if (found != NULL) {
        ptrdiff_t index = found - sales;

        printf("\nValue %d found at index %td\n", value, index);
        printf("Address of found is %p\n", (void *) found);
    } else {
        printf("\nValue %d not found\n", value);
    }

    reverse_array(sales, N);

    printf("\nReversed array:\n");
    print_array_forward_via_indices(sales, N);


    // Enter array from file
    int M;
    scanf("%d", &M);
    int sales2[M];
    for (int i = 0; i < M; ++i) {
        scanf("%d", sales2 + i);
    }

    return 0;
}