CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -s

all: app

app: main.o foo.o math.o
	$(CC) $(LDFLAGS) main.o foo.o math.o -o app

main.o: main.c math.h
	$(CC) $(CFLAGS) -c $< -o main.o

foo.o: foo.c
	$(CC) $(CFLAGS) -c $< -o foo.o

math.o: math.c math.h
	$(CC) $(CFLAGS) -c $< -o math.o

clean:
	rm -f app *.o