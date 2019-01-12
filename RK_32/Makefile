CC := gcc
CFLAGS := -std=c99 -Wall -ggdb
LFLAGS :=

pname := app.exe
OBJS.$(pname) = main.o mylib.o

build: $(pname)

run:
	./$(pname)

$(pname): $(OBJS.$(pname))
	$(CC) $^ -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm $(pname) -f
	rm $(OBJS.$(pname)) -f

