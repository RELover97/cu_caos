Commits:

1. gcc

`gcc -std=gnu17 main.c math.c -o app`

Посмотреть, какие команды gcc запускает под капотом:

`gcc -std=gnu17 -v main.c math.c -o app`

`gcc -std=gnu17 -### main.c math.c -o app``gcc -std=gnu17 -### main.c math.c -o app`

2. Preprocessor

Добавим директивы в `main.c`

`gcc -E main.c -o main.i`

Посчитать число строк в файле:

`wc -l main.c`

`wc -l main.i`
