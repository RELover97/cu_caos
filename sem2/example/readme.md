1. gcc

`gcc -std=gnu17 main.c math.c -o app`

Посмотреть, какие команды gcc запускает под капотом:

`gcc -std=gnu17 -v main.c math.c -o app`

`gcc -std=gnu17 -### main.c math.c -o app`