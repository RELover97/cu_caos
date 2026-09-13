all: app

app: main.o foo.o math.o
	gcc main.o foo.o math.o -o app

main.o: main.c math.h
	gcc -c main.c -o main.o

foo.o: foo.c
	gcc -c foo.c -o foo.o

math.o: math.c math.h
	gcc -c math.c -o math.o

clean:
	rm -f app *.o