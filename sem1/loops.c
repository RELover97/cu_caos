
const char *grade_letter(int score)
{
    if (score >= 90) {
        return "A";
    } else if (score >= 75) {
        return "B";
    } else if (score >= 60) {
        return "C";
    } else {
        return "F";
    }
}

void switch_op()
{
    int day = 3;
    switch (day) {
        case 1:
            printf("Понедельник\n");
            break;
        case 2:
            printf("Вторник\n");
            break;
        case 3:
            printf("Среда\n");
            break;
        default:
            printf("Другой день\n");
            break;
    }
}

void for_loop()
{
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) { 
            continue; 
        } // пропускаем чётные
        printf("%d ", i); // 1 3 5 7 9
    }

    for (int i = 2; i < 91; i++) {
        if (91 % i == 0) {
            printf("%d\n", i); // первый делитель: 7
            break;
        }
    }
}

int main()
{
    const char *letter = grade_letter(50);
    printf("%s\n", letter);

    switch_op();

    for_loop();
}