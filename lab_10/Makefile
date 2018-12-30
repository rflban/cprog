CC := gcc
CFLAGS := -std=c99 -ggdb -Wall -Werror -pedantic

PNAME := app.exe
TNAME := test.exe

build: $(PNAME)

$(PNAME): main.o my_list.o trie.o exit.o
	$(CC) $^ -o $@

$(TNAME): test.o my_list.o exit.o
	$(CC) $^ -o $@

%.o: %.c *.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm *.o -f
	rm *.gch -f
	rm $(PNAME) -f
	rm $(TNAME) -f
