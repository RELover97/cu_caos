long factorial(int n)
{
    if (n <= 1) { // базовый случай
        return 1;
    }

    return n * factorial(n - 1); // рекурсивный вызов
}

int main()
{
    for (int i = 0; i <= 10; i++) {
        printf("%2d! = %ld\n", i, factorial(i));
    }
}