CPP=gcc
CFLAGS= -Wall -Iinclude
LDFLAGS= -lSDLmain -lSDL
EXEC= main
SOURCE = src
OBJET = obj

SRC = $(wildcard $(SOURCE)/*.c)
OBJS = $(patsubst $(SOURCE)%.c,$(OBJET)%.o, $(SRC))


all: $(EXEC)

main : $(OBJS)
	$(CPP) -o $@ $^ $(LDFLAGS)

$(OBJET)/%.o : $(SOURCE)/%.c
	$(CPP) $(CFLAGS) -o $@ -c $<

clean:
	rm -fr *.o
	rm -f obj/*.o

cleaner: clean
	rm -fr $(EXEC)
