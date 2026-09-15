/*
    Задача
    На производстве записали количество изготовленных деталей за 4 дня для 5 станков.
    Строка — день, столбец — станок:
                Станки
        0  1  2  3  4
    День 0 8 12 10  7  9
    День 1 6 15 11  8 10
    День 2 9 14 13  6 12
    День 3 7 11  9 16 14

    Написать программу на C, которая:
    - хранит таблицу в обычном двумерном массиве фиксированного размера;
    - выводит таблицу;
    - вычисляет сумму деталей, произведённых каждым днём;
    - находит максимальный элемент и его координаты;
    - вычисляет сумму элементов главной диагонали;
    - транспонирует таблицу в другой массив;
    - во всех функциях обход выполняется через указатели, без a[i][j].

    Всё хранится на стеке
*/

#include <stdio.h>
#include <stddef.h>

enum {
    ROWS = 4,
    COLS = 5
};


void print_matrix_via_indices(const int (*a)[COLS], size_t rows)
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < COLS; ++j) {
            printf("%3d ", a[i][j]);
        }

        printf("\n");
    }
}


void print_matrix_via_ptrs(const int (*a)[COLS], size_t rows)
{
    const int (*row)[COLS] = a;

    for (size_t i = 0; i < ROWS; ++i) {
        const int *p = *row;
        const int *end = p + COLS;

        while (p != end) {
            printf("%d ", *p);
            ++p;
        }

        printf("\n");
        ++row; // row = row + 1;
    }
}


void print_matrix_via_ptrs_2(const int (*a)[COLS], size_t rows)
{
    const int *elem = *a;

    const int *a_elem_end = elem + COLS * rows;
    size_t j = 0;
    while (elem != a_elem_end) {
        if (j++ % COLS == 0) {
            printf("\n");
        }
        printf("%d ", *elem);
        ++elem;
    }
}


int row_sum(const int *row, size_t n)
{
    const int *p = row;
    const int *end = row + n;

    int sum = 0;

    while (p != end) {
        sum += *p;
        ++p;
    }

    return sum;
}


void print_row_sums(const int (*a)[COLS], size_t rows)
{
    const int (*row)[COLS] = a;
    const int (*end)[COLS] = a + rows;

    size_t row_number = 0;

    while (row != end) {
        printf("Row %zu: %d\n", row_number, row_sum(*row, COLS));
        ++row;
        ++row_number;
    }
}

const int *find_max(const int (*a)[COLS],
                    size_t rows,
                    size_t *out_row,
                    size_t *out_col)
{
    const int *max = &a[0][0];

    size_t max_row = 0;
    size_t max_col = 0;

    const int *p = &a[0][0];
    const int *end = &a[0][0] + rows * COLS;

    while (p != end) {
        if (*p > *max) {
            max = p;
        }

        ++p;
    }

    size_t index = (size_t)(max - &a[0][0]);

    max_row = index / COLS;
    max_col = index % COLS;

    *out_row = max_row;
    *out_col = max_col;

    return max;
}


int diagonal_sum(const int (*a)[COLS], size_t rows)
{
    size_t n = rows < COLS ? rows : COLS;

    int sum = 0;

    const int *p = &a[0][0];

    for (size_t i = 0; i < n; ++i) {
        sum += *p;
        p += COLS + 1;
    }

    return sum;
}

// Fix!!!
void transpose(const int (*src)[COLS],
               int (*dst)[ROWS],
               size_t rows)
{
    const int (*src_row)[COLS] = src;
    int (*dst_row)[ROWS] = dst;

    for (size_t i = 0; i < rows; ++i) {
        const int *src_element = *src_row;
        int *dst_element = dst[0];

        for (size_t j = 0; j < COLS; ++j) {
            int *destination = *(dst + j) + i;

            *destination = *src_element;

            ++src_element;
        }

        ++src_row;
    }
}

int main(void)
{
    // same as: int production[][COLS] = {...};
    int production[ROWS][COLS] = {
        {8, 12, 10, 7, 9},
        {6, 15, 11, 8, 10},
        {9, 14, 13, 6, 12},
        {7, 11, 9, 16, 14}
    };

    printf("Source matrix:\n");
    print_matrix_via_indices(production, ROWS);
    print_matrix_via_ptrs(production, ROWS);
    print_matrix_via_ptrs_2(production, ROWS);

    printf("\nRow sums:\n");
    print_row_sums(production, ROWS);

    size_t max_row;
    size_t max_col;

    const int *max = find_max(
        production,
        ROWS,
        &max_row,
        &max_col
    );

    printf("\nMaximum = %d\n", *max);
    printf("Position = [%zu][%zu]\n",
           max_row,
           max_col);

    printf("\nMain diagonal sum = %d\n",
           diagonal_sum(production, ROWS));

    /// fix!!!

    int transposed[COLS][ROWS];

    transpose(production, transposed, ROWS);

    printf("\nTransposed matrix:\n");
    print_matrix_via_indices(
        (const int (*)[COLS])transposed,
        COLS
    );

    return 0;
}