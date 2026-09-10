// Объявление (прототип) — компилятор заранее знает сигнатуру

int max_of_two(int a, int b);

const int global_const = 1; // константа и глобальная перменная

int main(void)
{
    // m - локальная переменная
    int m = max_of_two(7, 12); // вызов функции
    int m = max_of_two(12, 7);

    printf("max = %d\n", m);

    return 0;
}

// Определение — тело функции, выполняется при вызове
int max_of_two(int a, int b)
{
    static int c = 0; // статическая локальная переменная
    printf("%d\n", c);

    if (a > b) { 
        return a; 
    } else {
        return b;
    }
}