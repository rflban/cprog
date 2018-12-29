CC := gcc
CFLAGS := -std=c99 -ggdb -Wall #-Werror -pedantic
LFLAGS :=

PNAME := app.exe
TNAME := test.exe

OBJS.$(PNAME) = main.o mylib.o exit.o
OBJS.$(TNAME) = test.o mylib.o exit.o

$(PNAME): $(OBJS.$(PNAME))
	$(CC) $^ $(LFLAGS) -o $@

$(TNAME): $(OBJS.$(TNAME))
	$(CC) $^ $(LFLAGS) -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm $(PNAME) -f
	rm $(TNAME) -f
	rm $(OBJS.$(PNAME)) -f
	rm $(OBJS.$(TNAME)) -f
