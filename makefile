CC = gcc
CFLAGS = -Wall -I include
LDFLAGS = -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows

main : main.o
	$(CC) main.o -o main $(LDFLAGS)

main.o : src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o


clean :
	del -rf *.o

mrproper : clean
	del Programme
